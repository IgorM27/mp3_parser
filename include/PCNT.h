#pragma once

#include "Frame.h"

class PCNT : public Frame {
private:
    int counter;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] int GetCounter() const;
};