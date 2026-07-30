#include "ExtendHeader.h"

[[maybe_unused]] void ExtendHeader::SkipExtendHeader(std::ifstream& input) {
    std::vector<char> header;
    header.resize(4);
    for (int i = 0; i < 4; i++) {
        input >> header[i];
    }
    uint8_t bit;
    for (int j = 0; j < 4; j++) {
        bit = uint8_t(header[3 - j]);
        for (int i = 0; i < 7; i++) {
            size += (bit % 2) * (1 << (i + j * 7));
            bit >>= 1;
        }
    }
    input >> bytes;
    for (int i = 0; i < size - 5; i++) {
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

[[maybe_unused]] void ExtendHeader::PrintExtendHeader() {
    std::cout << "Extend Header:";
    std::cout << size << '\n';
    std::cout << bytes << '\n';
    for (auto& flag: flags) {
        for (int j: flag) {
            std::cout << j;
        }
        std::cout << '\n';
    }
}

[[maybe_unused]] int ExtendHeader::GetSize() const {
    return size;
}

