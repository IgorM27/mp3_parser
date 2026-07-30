#pragma once

#include "vector"
#include "fstream"
#include "iostream"

class ExtendHeader {
private:
    int size;
public:
    int bytes;
    std::vector<std::vector<int>> flags;

    [[maybe_unused]] void SkipExtendHeader(std::ifstream& input);

    [[maybe_unused]] void PrintExtendHeader();

    [[maybe_unused]] [[nodiscard]] int GetSize() const;
};
