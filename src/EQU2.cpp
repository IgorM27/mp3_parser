#include "EQU2.h"

void EQU2::SetInfo(std::ifstream& input) {
    char ch;
    input.get(interpolation_method);
    representation = "Interpolation method: ";
    representation += interpolation_method;
    representation += '\n';
    representation += "Identification: ";
    for (int i = 0; i < size - 1; ++i) {
        input.get(ch);
        identification += ch;
    }
    representation += identification;
    representation += '\n';
}

[[maybe_unused]] char EQU2::GetInterpolationMethod() const {
    return interpolation_method;
}

[[maybe_unused]] std::string EQU2::GetIdentification() const {
    return identification;
}

