#include <iostream>
#include <string>
#include <filesystem>
#include <unordered_map>

#include "parser.h"
#include "ID3_Header.h"
#include "ExtendHeader.h"
#include "Frame.h"

#include "MP3.h"


std::string ReadID(std::ifstream& input) {
    std::string result;
    char ch;
    for (int i = 0; i < 4; ++i) {
        input.get(ch);
        result += ch;
    }
    return result;
}

std::string Unsinchronisation(std::filesystem::path& name, int size) {
    std::string new_name = name.string().substr(0, name.string().size() - 4);
    new_name += "2.mp3";
    std::ifstream input(name, std::ios::binary);
    std::ofstream output(new_name, std::ios::binary);
    char buffer[3];
    input.read(buffer, 3);
    uint8_t first = 255;
    uint8_t second = 0;
    uint8_t third = 224;
    for (int i = 0; i < size - 3; ++i) {
        if (buffer[0] == first && buffer[1] == second && buffer[2] >= third) {
            output << buffer[0];
            buffer[0] = buffer[2];
            input.get(buffer[1]);
            input.get(buffer[2]);
            i--;
        } else {
            output << buffer[0];
            buffer[0] = buffer[1];
            buffer[1] = buffer[2];
            input.get(buffer[2]);
        }
    }
    if (buffer[0] == first && buffer[1] == second && buffer[2] >= third) {
        output << buffer[0];
        output << buffer[2];
    } else {
        output << buffer[0];
        output << buffer[1];
        output << buffer[2];
    }
    output.close();
    input.close();
    return new_name;
}


void ChangeFrame(const std::filesystem::path& name, std::string& frame,
                 std::unordered_map<std::string, std::string>& description,
                 std::string& value) {

    int new_size = static_cast<int>(std::filesystem::file_size(std::filesystem::path(value)));
    std::string new_name = name.string().substr(0, name.string().size() - 4);
    new_name += "1.mp3";
    std::filesystem::rename(std::filesystem::path(name), std::filesystem::path(new_name));
    std::ifstream input(new_name, std::ios::binary);
    std::ofstream output(name, std::ios::binary);

    ID3_Header header;
    header.ReadId3(input);
    int size = header.GetSize();
    int new_header;
    int new_frame;
    int delta;
    bool flag = false;
    int number = 0;
    if (header.GetFlagB()) {
        ExtendHeader a;
        a.SkipExtendHeader(input);
        number += a.GetSize();
    }
    while (size > 0) {
        std::string ID = ReadID(input);
        number += 4;
        if (ID == frame) {
            Frame tmp(ID);
            tmp.ReadFrame(input, description);
            delta = new_size - tmp.GetSize();
            new_frame = tmp.GetSize() + delta;
            flag = true;
            break;
        } else {
            Frame tmp(ID);
            tmp.ReadFrame(input, description);
            for (int i = 0; i < tmp.GetSize(); ++i) {
                char ch;
                input.get(ch);
            }
            size -= (tmp.GetSize() + 10);
            number += (tmp.GetSize() + 6);
        }
    }
    if (!flag) {
        std::cout << "The file does not contain such a frame!!!\n";
        return;
    }
    new_header = header.GetSize() + delta;
    std::string result_header;
    std::string result_frame;
    while (new_header > 0) {
        if (new_header % 2 == 1) {
            result_header += '1';
        } else {
            result_header += '0';
        }
        new_header = new_header / 2;
    }

    while (new_frame > 0) {
        if (new_frame % 2 == 1) {
            result_frame += '1';
        } else {
            result_frame += '0';
        }
        new_frame = new_frame / 2;
    }
    std::string result1;
    std::string result2;
    int counter = 0;
    uint8_t bit = 0;
    for (char i: result_header) {
        if (i == '1') {
            bit += (1 << counter);
        }
        counter++;
        if (counter % 7 == 0) {
            result1 += char(bit);
            bit = 0;
            counter = 0;
        }
    }
    result1 += char(bit);
    int r1 = static_cast<int>(result1.size());
    for (int i = 0; i < 4 - r1; ++i) {
        result1 += char(0);
    }
    std::reverse(result1.begin(), result1.end());
    counter = 0;
    bit = 0;
    for (char i: result_frame) {
        if (i == '1') {
            bit += (1 << counter);
        }
        counter++;
        if (counter % 7 == 0) {
            result2 += char(bit);
            bit = 0;
            counter = 0;
        }
    }
    result2 += char(bit);
    int r2 = static_cast<int>(result2.size());
    for (int i = 0; i < 4 - r2; ++i) {
        result2 += char(0);
    }
    std::reverse(result2.begin(), result2.end());
    input.close();
    std::ifstream input_res(new_name, std::ios::binary);
    char ch;
    for (int i = 0; i < 6; ++i) {
        input_res.get(ch);
        output << ch;
    }
    for (int i = 0; i < 4; ++i) {
        input_res.get(ch);
    }
    output << result1;
    for (int i = 0; i < number; ++i) {
        input_res.get(ch);
        output << ch;
    }
    output << result2;
    Frame a(frame);
    a.ReadFrame(input_res, description);
    for (int i = 0; i < a.GetSize(); ++i) {
        input_res.get(ch);
    }
    output << a.GetFirstFlag();
    output << a.GetSecondFlag();
    std::ifstream change(value);
    for (int i = 0; i < new_size; ++i) {
        change.get(ch);
        output << ch;
    }
    while (!input_res.eof()) {
        input_res.get(ch);
        output << ch;
    }
    change.close();
    input_res.close();
    output.close();
    std::filesystem::remove(std::filesystem::path(new_name));
}

int main(int argc, const char** argv) {

    Options options = FillOptions(argc, argv);

    MP3 mp3;

    if (options.change) {
        ChangeFrame(options.file, options.frame, mp3.description, options.value);
        std::cout << "The file has been successfully modified!!!";
    } else {
        std::ifstream input1(options.file, std::ios::binary);
        int size;
        mp3.header.ReadId3(input1);
        size = mp3.header.GetSize() - 10;
        std::string new_name = options.file.string();
        if (mp3.header.GetFlagA()) {
            new_name = Unsinchronisation(options.file, size);
        }
        input1.close();
        std::ifstream input(new_name, std::ios::binary);
        input.seekg(10);
        if (mp3.header.GetFlagB()) {
            mp3.extend_header.SkipExtendHeader(input);
            size -= mp3.extend_header.GetSize();
        }
        if (options.print_all) {
            mp3.PrintFrames(size, input);
        } else if (options.print_one) {
            bool flag = false;
            while (size > 0) {
                std::string ID = ReadID(input);
                if (ID == options.frame) {
                    mp3.PrintFrame(size, input, ID);
                    flag = true;
                    continue;
                } else {
                    Frame tmp(ID);
                    tmp.ReadFrame(input, mp3.description);
                    for (int i = 0; i < tmp.GetSize(); ++i) {
                        char ch;
                        input.get(ch);
                    }
                    size -= (tmp.GetSize() + 10);
                }
            }
            if (!flag) {
                std::cout << "The file does not contain such a frame!!!\n";
            }
        }
        input.close();
        if (mp3.header.GetFlagA()) {
            std::filesystem::remove(std::filesystem::path(new_name));
        }
    }
    return 0;
}
