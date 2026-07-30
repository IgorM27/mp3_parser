#include "LINK.h"

void LINK::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Frame identifier: ";
    for (int i = 0; i < 4; ++i) {
        input.get(ch);
        frame_identifier += ch;
    }
    representation += frame_identifier;
    representation += '\n';
    representation += "URL: ";
    bool flag = false;
    for (int i = 0; i < size - 4; ++i) {
        input.get(ch);
        if (ch == '\0' && !flag) {
            flag = true;
            representation += url;
            representation += '\n';
            representation += "ID and additional data: ";
            continue;
        }
        if (!flag) {
            url += ch;
        } else {
            additional_data += ch;
        }
    }
    representation += additional_data;
    representation += '\n';
}

[[maybe_unused]] std::string LINK::GetFrameIdentifier() const {
    return frame_identifier;
}

[[maybe_unused]] std::string LINK::GetURL() const {
    return url;
}

[[maybe_unused]] std::string LINK::GetAdditionalData() const {
    return additional_data;
}

