#include "SEEK.h"

void SEEK::SetInfo(std::ifstream& input) {
    char ch;
    input.get(ch);
    representation = "Minimum offset to next tag: ";
    std::string result;
    minimum_offset_to_next_tag = 0;
    for (int i = 0; i < size; ++i) {
        input >> ch;
        auto bit = uint8_t(ch);
        std::string tmp;
        for (int j = 7; j > 0; ++j) {
            if (bit % 2 == 0) {
                tmp += '0';
            } else {
                tmp += '1';
            }
            bit >> 1;
        }
        std::reverse(tmp.begin(), tmp.end());
        result += tmp;
    }
    for (int i = 0; i < result.size(); ++i) {
        if (result[result.size() - 1 - i] == '1') {
            minimum_offset_to_next_tag += 1 << i;
        }
    }
    representation += std::to_string(minimum_offset_to_next_tag);
    representation += '\n';
}

[[maybe_unused]] int SEEK::GetMinimumOffsetToNextTag() const {
    return minimum_offset_to_next_tag;
}

