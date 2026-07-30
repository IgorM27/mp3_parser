#include "COMR.h"

void COMR::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Text encoding: ";
    input.get(text_encoding);
    representation += text_encoding;
    representation += '\n';
    int counter = 1;
    representation += "Price string: ";
    std::string price_;
    input.get(ch);
    while (ch != '\0') {
        price_ += ch;
        counter++;
        input.get(ch);
    }
    price = std::strtol(price_.c_str(), nullptr, 10);
    representation += price_;
    representation += '\n';
    representation += "Valid until: ";
    for (int i = 0; i < 8; ++i) {
        input.get(ch);
        valid_until += ch;
        if (i == 3 || i == 5) {
            valid_until += ' ';
        }
    }
    representation += valid_until;
    representation += '\n';
    representation += "Contact URL: ";
    counter++;
    input.get(ch);
    while (ch != '\0') {
        representation += ch;
        counter++;
        input.get(ch);
    }
    representation += '\n';
    representation += "Received as: ";
    input.get(received);
    representation += received;
    representation += '\n';
    representation += "Name of seller: ";
    counter++;
    input.get(ch);
    while (ch != '\0') {
        seller_name += ch;
        counter++;
        input.get(ch);
    }
    representation += seller_name;
    representation += '\n';
    representation += "Description: ";
    counter++;
    input.get(ch);
    while (ch != '\0') {
        product_description += ch;
        counter++;
        input.get(ch);
    }
    representation += product_description;
    representation += '\n';
    representation += "Picture MIME type: ";
    counter++;
    input.get(ch);
    while (ch != '\0') {
        MIME_type += ch;
        counter++;
        input.get(ch);
    }
    representation += MIME_type;
    representation += '\n';
    representation += "Seller logo: ";
    for (int i = 0; i < size - counter - 10; ++i) {
        input.get(ch);
        seller_logo.emplace_back(ch);
        representation += ch;
    }
    representation += '\n';
}

char COMR::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] int COMR::GetPrice() const {
    return price;
}

[[maybe_unused]] std::string COMR::GetValidUntil() const {
    return valid_until;
}

[[maybe_unused]] std::string COMR::GetURL() const {
    return url;
}

[[maybe_unused]] char COMR::GetReceived() const {
    return received;
}

[[maybe_unused]] std::string COMR::GetSellerName() const {
    return seller_name;
}

[[maybe_unused]] std::string COMR::GetProductDescription() const {
    return product_description;
}

[[maybe_unused]] std::string COMR::GetMIMEType() const {
    return MIME_type;
}

[[maybe_unused]] std::deque<char> COMR::GetSellerLogo() const {
    return seller_logo;
}

