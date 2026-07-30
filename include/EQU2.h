#pragma once

#include "Frame.h"

class EQU2 : public Frame {
private:
    char interpolation_method;
    std::string identification;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetInterpolationMethod() const;

    [[maybe_unused]] [[nodiscard]] std::string GetIdentification() const;
};
