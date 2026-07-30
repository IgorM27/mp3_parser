#pragma once

#include "Frame.h"

class RVA2 : public Frame {
private:
    std::string identification;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetIdentification() const;
};