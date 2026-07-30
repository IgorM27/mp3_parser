#include "URLFrame.h"

void URLFrame::SetInfo(std::ifstream& input) {
    char ch;
    representation += "URL: ";
    for (int i = 0; i < size; ++i) {
        input.get(ch);
        url += ch;
    }
    representation += url;
    representation += '\n';
}

[[maybe_unused]] std::string URLFrame::GetURL() const {
    return url;
}

