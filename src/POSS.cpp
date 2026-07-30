#include "POSS.h"

void POSS::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Time stamp format: ";
    input.get(time_stamp_format);
    representation += time_stamp_format;
    representation += '\n';
    representation += "Position: ";
    std::string result;
    position = 0;
    for (int i = 0; i < size - 1; ++i) {
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
            position += 1 << i;
        }
    }
    representation += std::to_string(position);
    representation += '\n';
}

[[maybe_unused]] char POSS::GetTimeStampFormat() const {
    return time_stamp_format;
}

[[maybe_unused]] int POSS::GetPosition() const {
    return position;
}

