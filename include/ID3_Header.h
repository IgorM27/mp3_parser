#pragma once

#include "iostream"
#include "string"
#include "vector"
#include <fstream>

class ID3_Header{
private:
    std::string head = "ID3";
    uint8_t  version;
    uint8_t sub_version;
    bool flag_a;
    bool flag_b;
    bool flag_c;
    bool flag_d;
    int size;

public:

    void ReadId3(std::ifstream& input);
    void Print();

    [[maybe_unused]] static void SkipExtendedHeader(std::ifstream& input);

    [[maybe_unused]] std::string GetHead();

    [[maybe_unused]] [[nodiscard]] uint8_t GetVersion() const;

    [[maybe_unused]] [[nodiscard]] uint8_t GetSubversion() const;

    [[maybe_unused]] [[nodiscard]] bool GetFlagA() const;
    [[nodiscard]] bool GetFlagB() const;

    [[maybe_unused]] [[nodiscard]] bool GetFlagC() const;

    [[maybe_unused]] [[nodiscard]] bool GetFlagD() const;
    [[nodiscard]] int GetSize() const;
};
