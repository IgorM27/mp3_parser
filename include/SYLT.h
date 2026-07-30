#pragma once

#include "Frame.h"

class SYLT : public Frame {
private:
    char text_encoding;
    std::string language;
    char time_stamp_format;
    char content_type;
    std::string content_descriptor;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] std::string GetLanguage() const;

    [[maybe_unused]] [[nodiscard]] char GetTimeStampFormat() const;

    [[maybe_unused]] [[nodiscard]] char GetContentType() const;

    [[maybe_unused]] [[nodiscard]] std::string GetContentDescriptor() const;
};
