#pragma once

#include <string>
#include <vector>
#include "filesystem"

struct Options {
    bool print_all = false;
    bool print_one = false;
    bool change = false;
    std::string frame;
    std::string value;
    std::filesystem::path file;
};

Options FillOptions(int argc, const char** argv);
