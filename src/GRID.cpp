#include "GRID.h"

void GRID::SetInfo(std::ifstream& input) {
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
    representation += "Group symbol: ";
    input.get(group_symbol);
    representation += group_symbol;
    representation += '\n';
    representation += "Group dependent data: ";
    for (int i = 0; i < size - counter - 1; ++i) {
        input.get(ch);
        group_depended_data += ch;
    }
    representation += group_depended_data;
    representation += '\n';
}

[[maybe_unused]] std::string GRID::GetOwnerIdentifier() const {
    return owner_identifier;
}

[[maybe_unused]] char GRID::GetGroupSymbol() const {
    return group_symbol;
}

[[maybe_unused]] std::string GRID::GetGroupDependedData() const {
    return group_depended_data;
}

