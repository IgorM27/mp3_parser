#pragma once

#include "Frame.h"

class TXXX : public Frame {
private:
    char text_encoding;
    std::string frame_description;
    std::string value;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] std::string GetFrameDescription() const;

    [[maybe_unused]] [[nodiscard]] std::string GetValue() const;
};
