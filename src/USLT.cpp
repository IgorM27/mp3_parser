#include "USLT.h"

void USLT::SetInfo(std::ifstream& input) {
    char ch;
    representation += "Text encoding: ";
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
    representation += "Content descriptor: ";
    bool flag = false;
    for (int i = 0; i < size - 4; ++i) {
        input.get(ch);
        if (ch == '\0' && !flag) {
            flag = true;
            representation += content_descriptor;
            representation += '\n';
            representation += "Lyrics/text: ";
            continue;
        }
        if (!flag) {
            content_descriptor += ch;
        } else {
            text += ch;
        }
    }
    representation += text;
    representation += '\n';
}

char USLT::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] std::string USLT::GetLanguage() const {
    return language;
}

[[maybe_unused]] std::string USLT::GetContentDescriptor() const {
    return content_descriptor;
}

[[maybe_unused]] std::string USLT::GetText() const {
    return text;
}

