#pragma once

#include "Frame.h"

class OWNE : public Frame {
private:
    char text_encoding;
    [[maybe_unused]] int price_paid;
    std::string date_purchase;
    std::string seller;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] int GetPricePaid() const;

    [[maybe_unused]] [[nodiscard]] std::string GetDatePurchase() const;

    [[maybe_unused]] [[nodiscard]] std::string GetSeller() const;
};