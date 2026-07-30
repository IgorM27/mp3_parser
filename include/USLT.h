#pragma once

#include "Frame.h"

class USLT : public Frame {
private:
    char text_encoding;
    std::string language;
    std::string content_descriptor;
    std::string text;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] std::string GetLanguage() const;

    [[maybe_unused]] [[nodiscard]] std::string GetContentDescriptor() const;

    [[maybe_unused]] [[nodiscard]] std::string GetText() const;
};