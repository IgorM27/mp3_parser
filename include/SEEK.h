#pragma once

#include "Frame.h"

class SEEK : public Frame {
private:
    int minimum_offset_to_next_tag;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] int GetMinimumOffsetToNextTag() const;
};