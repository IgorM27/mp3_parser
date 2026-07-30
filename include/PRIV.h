#pragma once

#include "Frame.h"

class PRIV : public Frame {
private:
    std::string owner_identifier;
    std::string private_data;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetOwnerIdentifier() const;

    [[maybe_unused]] [[nodiscard]] std::string GetPrivateData() const;
};