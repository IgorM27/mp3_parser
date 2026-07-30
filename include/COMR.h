#pragma once

#include "Frame.h"
#include "deque"

class COMR : public Frame {
private:
    char text_encoding;
    [[maybe_unused]] int price;
    std::string valid_until;
    std::string url;
    char received;
    std::string seller_name;
    std::string product_description;
    std::string MIME_type;
    std::deque<char> seller_logo;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] char GetTextEncoding() const;

    [[maybe_unused]] [[nodiscard]] int GetPrice() const;

    [[maybe_unused]] [[nodiscard]] std::string GetValidUntil() const;

    [[maybe_unused]] [[nodiscard]] std::string GetURL() const;

    [[maybe_unused]] [[nodiscard]] char GetReceived() const;

    [[maybe_unused]] [[nodiscard]] std::string GetSellerName() const;

    [[maybe_unused]] [[nodiscard]] std::string GetProductDescription() const;

    [[maybe_unused]] [[nodiscard]] std::string GetMIMEType() const;

    [[maybe_unused]] [[nodiscard]] std::deque<char> GetSellerLogo() const;
};