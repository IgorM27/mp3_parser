#include "SYLT.h"


void SYLT::SetInfo(std::ifstream& input) {
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
    input.get(time_stamp_format);
    representation += "Time stamp format: ";
    representation += time_stamp_format;
    representation += '\n';
    input.get(content_type);
    representation += "Content type: ";
    representation += content_type;
    representation += '\n';
    representation += "Content descriptor: ";
    for (int i = 0; i < size - 7; ++i) {
        input.get(ch);
        content_descriptor += ch;
    }
    representation += content_descriptor;
    representation += '\n';
}

[[maybe_unused]] char SYLT::GetTextEncoding() const {
    return text_encoding;
}

[[maybe_unused]] std::string SYLT::GetLanguage() const {
    return language;
}

[[maybe_unused]] char SYLT::GetTimeStampFormat() const {
    return time_stamp_format;
}

[[maybe_unused]] char SYLT::GetContentType() const {
    return content_type;
}

[[maybe_unused]] std::string SYLT::GetContentDescriptor() const {
    return content_descriptor;
}
