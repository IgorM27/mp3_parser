#include "COMM.h"

void COMM::SetInfo(std::ifstream& input) {
    char ch;
    representation = "Text encoding: ";
    input.get(text_encoding);
    representation += text_encoding;
    representation += '\n';
    representation += "Language: ";
    for (int i = 0; i < 3; ++i) {
        input.get(ch);
        language += ch;
    }
    representation += language;
    representation += '\n';
    representation += "Short content description: ";
    bool flag = false;
    for (int i = 0; i < size - 4; ++i) {
        input.get(ch);
        if (ch == '\0' && !flag) {
            flag = true;
            representation += '\n';
            representation += "The actual text: ";
            continue;
        }
        representation += ch;
        if (!flag) {
            content_description += ch;
        } else {
            text += ch;
        }
    }
    representation += '\n';
}

[[maybe_unused]] char COMM::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] std::string COMM::GetLanguage() const {
    return language;
}

[[maybe_unused]] std::string COMM::GetContentDescription() const {
    return content_description;
}

[[maybe_unused]] std::string COMM::GetText() const {
    return text;
}
