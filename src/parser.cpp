#include "parser.h"
#include "iostream"

struct OptionsInString {

    const std::string kFileLong = "--file";
    const std::string kFileShort = "-f";

    const std::string kAllLong = "--all";
    const std::string kAllShort = "-a";

    const std::string kOneLong = "--one";
    const std::string kOneShort = "-o";

    const std::string kChangeLong = "--change";
    const std::string kChangeShort = "-c";

    const std::string kValueLong = "--value";
    const std::string kValueShort = "-v";

    const std::string kFrameLong = "--frame";
    const std::string kFrameShort = "-F";
};


Options FillOptions(int argc, const char** argv) {
    OptionsInString comparable;
    Options result;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            std::string option = argv[i];

            if (option == comparable.kAllLong || option == comparable.kAllShort) {
                result.print_all = true;
            } else if (option == comparable.kOneShort || option == comparable.kOneLong) {
                result.print_one = true;
            } else if (option == comparable.kChangeShort || option == comparable.kChangeLong) {
                result.change = true;

            } else if (option == comparable.kFileShort || option == comparable.kFileLong) {
                result.file = argv[i + 1];
                i++;
            } else if (option == comparable.kFrameShort || option == comparable.kFrameLong) {
                result.frame = argv[i + 1];
                i++;
            } else if (option == comparable.kValueShort || option == comparable.kValueLong) {
                result.value = argv[i + 1];
                i++;
            } else {
                std::cerr << "Error! Bad Argument!";
            }
        } else {
            std::cerr << "Error! Bad Argument!";
        }
    }

    return result;
}
