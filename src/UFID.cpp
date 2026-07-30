#include "UFID.h"

void UFID::SetInfo(std::ifstream& input) {
    char ch;
    input.get(owner_identifier);
    representation += "Owner Identifier: ";
    representation += owner_identifier;
    representation += '\n';
    representation += "Identifier: ";
    for (int i = 0; i < size - 1; ++i) {
        input.get(ch);
        identifier += ch;
    }
    representation += identifier;
    representation += '\n';
}

[[maybe_unused]] char UFID::GetOwnerIdentifier() const {
    return owner_identifier;
}

[[maybe_unused]] std::string UFID::GetIdentifier() const {
    return identifier;
}
