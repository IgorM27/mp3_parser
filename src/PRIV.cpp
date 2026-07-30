#include "PRIV.h"

void PRIV::SetInfo(std::ifstream& input) {
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
    representation += "The private data: ";
    for (int i = 0; i < size - counter; ++i) {
        input.get(ch);
        private_data += ch;
    }
    representation += private_data;
    representation += '\n';
}

[[maybe_unused]] std::string PRIV::GetOwnerIdentifier() const {
    return owner_identifier;
}

[[maybe_unused]] std::string PRIV::GetPrivateData() const {
    return private_data;
}

