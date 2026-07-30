#pragma once

#include "Frame.h"

class UFID : public Frame {
private:
    char owner_identifier;
    std::string identifier;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetOwnerIdentifier() const;

    [[maybe_unused]] [[nodiscard]] std::string GetIdentifier() const;
};