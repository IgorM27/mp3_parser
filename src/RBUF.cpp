#include "RBUF.h"

void RBUF::SetInfo(std::ifstream& input) {
    char ch;
    std::string result;
    buffer_size = 0;
    representation = "Buffer size: ";
    for (int i = 0; i < 3; ++i) {
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
            buffer_size += 1 << i;
        }
    }
    representation += std::to_string(buffer_size);
    representation += '\n';
    representation += "Embedded info flag: ";
    input.get(embedded_info_flag);
    representation += embedded_info_flag;
    representation += '\n';
    representation += "Offset to next tag: ";
    offset_to_next_tag = 0;
    for (int i = 0; i < size - 4; ++i) {
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
            offset_to_next_tag += 1 << i;
        }
    }
    representation += std::to_string(offset_to_next_tag);
    representation += '\n';
}

[[maybe_unused]] int RBUF::GetBufferSize() const {
    return buffer_size;
}

[[maybe_unused]] char RBUF::GetEmbeddedInfoFlag() const {
    return embedded_info_flag;
}

[[maybe_unused]] int RBUF::GetOffsetToNextTag() const {
    return offset_to_next_tag;
}

