#include "Frame.h"

void Frame::ReadFrame(std::ifstream& input, std::unordered_map<std::string, std::string>& description_) {
    std::vector<char> buffer;
    buffer.resize(4);
    for (int i = 0; i < 4; i++) {
        input.get(buffer[i]);
    }
    int size_ = 0;
    uint8_t bit;
    for (int j = 0; j < 4; j++) {
        bit = uint8_t(buffer[3 - j]);
        for (int i = 0; i < 7; i++) {
            size_ += (bit % 2) * (1 << (i + j * 7));
            bit >>= 1;
        }
    }
    size = size_;
    input.get(first_flag);
    input.get(second_flag);
    description = description_[ID];
}

[[maybe_unused]] void Frame::PrintAllInformation() {
    std::cout << ID << '\n';
    std::cout << size << '\n';
    std::cout << first_flag << ' ' << second_flag << '\n';
    std::cout << representation << '\n';
    std::cout << "Frame description : " << description << '\n';
}


std::string Frame::GetID() const {
    return ID;
}

std::string Frame::GetRepresentation() const {
    return representation;
}

std::string Frame::GetDescription() const {
    return description;
}

[[maybe_unused]] char Frame::GetFirstFlag() const {
    return first_flag;
}

[[maybe_unused]] char Frame::GetSecondFlag() const {
    return second_flag;
}

int Frame::GetSize() const {
    return size;
}

void Frame::SetInfo(std::ifstream& input) {
}

void Frame::Print(std::ifstream& input, std::unordered_map<std::string, std::string>& description_) {
    ReadFrame(input, description_);
    SetInfo(input);
    std::cout << GetID() << '\n';
    std::cout << "Frame Description: " << GetDescription() << '\n';
    std::cout << GetRepresentation();
    std::cout << '\n';
}


