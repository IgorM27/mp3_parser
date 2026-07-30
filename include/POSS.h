#pragma once

#include "Frame.h"

class POSS : public Frame {
private:
    char time_stamp_format;
    int position;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTimeStampFormat() const;

    [[maybe_unused]] [[nodiscard]] int GetPosition() const;
};