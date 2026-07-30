#include "ID3_Header.h"

void ID3_Header::ReadId3(std::ifstream& input) {
    std::vector<char> header;
    header.resize(10);
    for (int i = 0; i < 10; i++) {
        input.get(header[i]);
    }
    std::vector<int> flags;
    version = int(header[3]);
    sub_version = int(header[4]);
    flags.resize(8);
    auto flag = uint8_t(header[5]);
    for (int i = 0; i < 8; i++) {
        flags[7 - i] = flag % 2;
        flag >>= 1;
    }
    flag_a = flags[0];
    flag_b = flags[1];
    flag_c = flags[2];
    flag_d = flags[3];
    int size_ = 0;
    uint8_t bit;
    for (int j = 0; j < 4; j++) {
        bit = uint8_t(header[9 - j]);
        for (int i = 0; i < 7; i++) {
            size_ += (bit % 2) * (1 << (i + j * 7));
            bit >>= 1;
        }
    }
    size = size_;
}

void ID3_Header::Print() {
    std::cout << "Header: ";
    std::cout << head << '\n';
    std::cout << int(version) << '.' << int(sub_version) << '\n';
    std::cout << flag_a << ' ' << flag_b << ' ' << flag_c << ' ' << flag_d << '\n';
    std::cout << size << '\n';
}

[[maybe_unused]] std::string ID3_Header::GetHead() {
    return head;
}

[[maybe_unused]] uint8_t ID3_Header::GetVersion() const {
    return version;
}

[[maybe_unused]] uint8_t ID3_Header::GetSubversion() const {
    return sub_version;
}

[[maybe_unused]] bool ID3_Header::GetFlagA() const {
    return flag_a;
}

bool ID3_Header::GetFlagB() const {
    return flag_b;
}

[[maybe_unused]] bool ID3_Header::GetFlagC() const {
    return flag_c;
}

[[maybe_unused]] bool ID3_Header::GetFlagD() const {
    return flag_d;
}

int ID3_Header::GetSize() const {
    return size;
}

[[maybe_unused]] void ID3_Header::SkipExtendedHeader(std::ifstream& input) {
    std::vector<char> header;
    header.resize(4);
    for (int i = 0; i < 4; i++) {
        input >> header[i];
    }
    int size_ = 0;
    uint8_t bit;
    for (int j = 0; j < 4; j++) {
        bit = uint8_t(header[3 - j]);
        for (int i = 0; i < 7; i++) {
            size_ += (bit % 2) * (1 << (i + j * 7));
            bit >>= 1;
        }
    }
    int number_flags;
    input >> number_flags;
    std::vector<std::vector<int>> flags;
    for (int i = 0; i < number_flags; i++) {
        std::vector<int> flags_;
        flags_.resize(8);
        int flag;
        input >> flag;
        for (int j = 0; j < 8; j++) {
            flags_[7 - j] = flag % 2;
            flag >>= 1;
        }
        flags.emplace_back(flags_);
    }
}
