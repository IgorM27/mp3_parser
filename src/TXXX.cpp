#include "TXXX.h"

void TXXX::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Text encoding: ";
    input.get(text_encoding);
    representation += text_encoding;
    representation += '\n';
    representation += "Description: ";
    bool flag = false;
    for (int i = 0; i < size - 1; ++i) {
        input.get(ch);
        if (ch == '\0' && !flag) {
            representation += frame_description;
            representation += '\n';
            representation += "Value: ";
            flag = true;
            continue;
        }
        if (!flag) {
            frame_description += ch;
        } else {
            value += ch;
        }
    }
    representation += value;
    representation += '\n';
}

char TXXX::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] std::string TXXX::GetFrameDescription() const {
    return frame_description;
}

[[maybe_unused]] std::string TXXX::GetValue() const {
    return value;
}

