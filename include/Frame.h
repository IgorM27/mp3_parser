#pragma once

#include "iostream"
#include "string"
#include <unordered_map>
#include <vector>
#include <fstream>


class Frame {
protected:
    std::string ID;
    std::string representation;
    std::string description;
    int size{};
    char first_flag{};
    char second_flag{};

public:
    explicit Frame(const std::string& tmp) {
        ID = tmp;
    }

    void ReadFrame(std::ifstream& input, std::unordered_map<std::string, std::string>& description_);

    [[maybe_unused]] void PrintAllInformation();

    [[nodiscard]] std::string GetID() const;

    [[nodiscard]] std::string GetRepresentation() const;

    [[nodiscard]] std::string GetDescription() const;

    [[maybe_unused]] [[nodiscard]] char GetFirstFlag() const;

    [[maybe_unused]] [[nodiscard]] char GetSecondFlag() const;

    [[nodiscard]] int GetSize() const;

    virtual void SetInfo(std::ifstream& input);

    void Print(std::ifstream& input, std::unordered_map<std::string, std::string>& description_);
};