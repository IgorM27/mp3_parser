#pragma once

#include "Frame.h"

class WXXX : public Frame {
private:
    std::string frame_description;
    std::string url;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetFrameDescription() const;

    [[maybe_unused]] [[nodiscard]] std::string GetURL() const;
};
