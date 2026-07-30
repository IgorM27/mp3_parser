#include "WXXX.h"

void WXXX::SetInfo(std::ifstream& input) {
    char ch;
    representation += "Description: ";
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        input.get(ch);
        if (ch == '\0' && !flag) {
            flag = true;
            representation += frame_description;
            representation += '\n';
            representation += "URL: ";
            continue;
        }
        if (!flag) {
            frame_description += ch;
        } else {
            url += ch;
        }
    }
    representation += url;
    representation += '\n';
}

[[maybe_unused]] std::string WXXX::GetFrameDescription() const {
    return frame_description;
}

[[maybe_unused]] std::string WXXX::GetURL() const {
    return url;
}
