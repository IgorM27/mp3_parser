#include "RVA2.h"

void RVA2::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Identification: ";
    for (int i = 0; i < size; ++i) {
        input.get(ch);
        identification += ch;
    }
    representation += identification;
    representation += '\n';
}

[[maybe_unused]] std::string RVA2::GetIdentification() const {
    return identification;
}
