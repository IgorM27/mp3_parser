#pragma once

#include "Frame.h"

class COMM : public Frame {
private:
    char text_encoding;
    std::string language;
    std::string content_description;
    std::string text;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] std::string GetLanguage() const;

    [[maybe_unused]] [[nodiscard]] std::string GetContentDescription() const;

    [[maybe_unused]] [[nodiscard]] std::string GetText() const;
};