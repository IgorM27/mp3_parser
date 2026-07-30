#include "ETCO.h"

void ETCO::SetInfo(std::ifstream& input) {
    representation = "Time stamp format: ";
    input.get(time_stamp_format);
    representation += time_stamp_format;
    representation += '\n';
}

[[maybe_unused]] char ETCO::GetTimeStampFormat() const {
    return time_stamp_format;
}

