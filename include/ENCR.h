#pragma once

#include "Frame.h"

class ENCR : public Frame {
private:
    std::string owner_identifier;
    char method_symbol;
    std::string encrypting_data;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetOwnerIdentifier() const;

    [[maybe_unused]] [[nodiscard]] char GetMethodSymbol() const;

    [[maybe_unused]] [[nodiscard]] std::string GetEncryptingData() const;
};