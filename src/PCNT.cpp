#include "PCNT.h"

void PCNT::SetInfo(std::ifstream& input) {
    char ch;
    counter = 0;
    representation = "Counter: ";
    std::string result;
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
            counter += 1 << i;
        }
    }
    representation += std::to_string(counter);
    representation += '\n';
}

[[maybe_unused]] int PCNT::GetCounter() const {
    return counter;
}

