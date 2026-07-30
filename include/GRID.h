#pragma once

#include "Frame.h"

class GRID : public Frame {
private:
    std::string owner_identifier;
    char group_symbol;
    std::string group_depended_data;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetOwnerIdentifier() const;

    [[maybe_unused]] [[nodiscard]] char GetGroupSymbol() const;

    [[maybe_unused]] [[nodiscard]] std::string GetGroupDependedData() const;
};