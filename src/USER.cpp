#include "USER.h"

void USER::SetInfo(std::ifstream& input) {
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
    representation += "The actual text: ";
    for (int i = 0; i < size - 4; ++i) {
        input.get(ch);
        text += ch;
    }
    representation += text;
    representation += '\n';
}

char USER::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] std::string USER::GetLanguage() const {
    return language;
}

[[maybe_unused]] std::string USER::GetText() const {
    return text;
}

