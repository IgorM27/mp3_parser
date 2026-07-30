#pragma once

#include "Frame.h"

class URLFrame : public Frame {
private:
    std::string url;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetURL() const;
};