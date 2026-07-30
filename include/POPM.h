#pragma once

#include "Frame.h"

class POPM : public Frame {
private:
    std::string email_user;
    int rating;
    int counter;
public:
    using Frame::Frame;

    void SetInfo(std::ifstream& input) override;

    [[maybe_unused]] [[nodiscard]] std::string GetEmailUser() const;

    [[maybe_unused]] [[nodiscard]] int GetRating() const;

    [[maybe_unused]] [[nodiscard]] int GetCounter() const;
};