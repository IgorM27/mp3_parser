#pragma once

#include "Frame.h"

class LINK : public Frame {
private:
    std::string frame_identifier;
    std::string url;
    std::string additional_data;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetFrameIdentifier() const;

    [[maybe_unused]] [[nodiscard]] std::string GetURL() const;

    [[maybe_unused]] [[nodiscard]] std::string GetAdditionalData() const;
};