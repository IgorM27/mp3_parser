#include "OWNE.h"

void OWNE::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Text encoding: ";
    input.get(text_encoding);
    representation += text_encoding;
    representation += '\n';
    representation += "Price paid: ";
    std::string price;
    int counter = 1;
    input.get(ch);
    while (ch != '\0') {
        price += ch;
        counter++;
        input.get(ch);
    }
    price_paid = std::strtol(price.c_str(), nullptr, 10);
    representation += price;
    representation += '\n';
    representation += "Date of purchase: ";
    for (int i = 0; i < 8; ++i) {
        input.get(ch);
        date_purchase += ch;
        if (i == 3 || i == 5) {
            date_purchase += ' ';
        }
    }
    representation += date_purchase;
    representation += '\n';
    representation += "Seller: ";
    for (int i = 0; i < size - counter - 8; ++i) {
        input.get(ch);
        seller += ch;
    }
    representation += seller;
    representation += '\n';
}

[[maybe_unused]] char OWNE::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] int OWNE::GetPricePaid() const {
    return price_paid;
}

[[maybe_unused]] std::string OWNE::GetDatePurchase() const {
    return date_purchase;
}

[[maybe_unused]] std::string OWNE::GetSeller() const {
    return seller;
}

