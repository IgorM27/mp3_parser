#pragma once

#include "Frame.h"

class ETCO : public Frame {
private:
    char time_stamp_format;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTimeStampFormat() const;
};
