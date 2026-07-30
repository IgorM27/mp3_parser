#include "POPM.h"

void POPM::SetInfo(std::ifstream& input) {
    char ch;
    int counter_ = 1;
    representation = "Email to user: ";
    input.get(ch);
    while (ch != '\0') {
        representation += ch;
        counter_++;
        input.get(ch);
    }
    representation += '\n';
    input.get(ch);
    rating = uint8_t(ch);
    representation += "Rating: ";
    representation += std::to_string(rating);
    representation += '\n';
    representation += "Counter: ";
    counter_++;
    counter = 0;
    std::string result;
    for (int i = 0; i < size - counter_; ++i) {
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

[[maybe_unused]] std::string POPM::GetEmailUser() const {
    return email_user;
}

[[maybe_unused]] int POPM::GetRating() const {
    return rating;
}

[[maybe_unused]] int POPM::GetCounter() const {
    return counter;
}

