#pragma once

#include "Frame.h"

class TextFrame : public Frame {
private:
    char text_encoding;
    std::string information;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] std::string GetInformation() const;
};