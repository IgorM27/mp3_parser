#pragma once

#include "Frame.h"

class RBUF : public Frame {
private:
    int buffer_size;
    char embedded_info_flag;
    int offset_to_next_tag;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] int GetBufferSize() const;

    [[maybe_unused]] [[nodiscard]] char GetEmbeddedInfoFlag() const;

    [[maybe_unused]] [[nodiscard]] int GetOffsetToNextTag() const;
};