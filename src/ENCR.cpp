#include "ENCR.h"

void ENCR::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Owner identifier: ";
    int counter = 1;
    input.get(ch);
    while (ch != '\0') {
        owner_identifier += ch;
        counter++;
        input.get(ch);
    }
    representation += owner_identifier;
    representation += '\n';
    representation += "Method symbol: ";
    input.get(method_symbol);
    representation += method_symbol;
    representation += '\n';
    representation += "Encryption data: ";
    for (int i = 0; i < size - counter - 1; ++i) {
        input.get(ch);
        encrypting_data += ch;
    }
    representation += encrypting_data;
    representation += '\n';
}

[[maybe_unused]] std::string ENCR::GetOwnerIdentifier() const {
    return owner_identifier;
}

[[maybe_unused]] char ENCR::GetMethodSymbol() const {
    return method_symbol;
}

[[maybe_unused]] std::string ENCR::GetEncryptingData() const {
    return encrypting_data;
}

