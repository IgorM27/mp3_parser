#include "TextFrame.h"

void TextFrame::SetInfo(std::ifstream& input) {
    representation += "Text encoding: ";
    char ch;
    input.get(text_encoding);
    representation += text_encoding;
    representation += '\n';
    representation += "Information: ";
    for (int i = 0; i < size - 1; ++i) {
        input.get(ch);
        information += ch;
    }
    representation += information;
    representation += '\n';
}

[[maybe_unused]] char TextFrame::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] std::string TextFrame::GetInformation() const {
    return information;
}
