
#include "MP3.h"


MP3::MP3() {
    std::ifstream input(R"(..\\include\FramesDescription.txt)", std::ios::binary);
    while (!(input.eof())) {
        char ch;
        std::string frame_id;
        std::string description_;
        for (int i = 0; i < kIDSize; i++) {
            input.get(ch);
            frame_id += ch;
        }
        input.get(ch);
        input.get(ch);
        while (ch != '\r' and !(input.eof())) {
            description_ += ch;
            input.get(ch);
        }
        input.get(ch);
        description.emplace(frame_id, description_);
    }
}

void MP3::PrintFrame(int& size, std::ifstream& input, const std::string& ID) {
    if (ID[0] == 'T' && ID != "TXXX") {
        TextFrame tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "TXXX") {
        TXXX tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID[0] == 'W' && ID != "WXXX") {
        URLFrame tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "COMM") {
        COMM tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "COMR") {
        COMR tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "ENCR") {
        ENCR tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "EQU2") {
        EQU2 tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "ETCO") {
        ETCO tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "GRID") {
        GRID tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "LINK") {
        LINK tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "OWNE") {
        OWNE tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "PCNT") {
        PCNT tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "POPM") {
        POPM tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "POSS") {
        POSS tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "PRIV") {
        PRIV tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "RBUF") {
        RBUF tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "RVA2") {
        RVA2 tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "SEEK") {
        SEEK tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "SYLT") {
        SYLT tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "UFID") {
        UFID tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "USER") {
        USER tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else if (ID == "USLT") {
        USLT tmp(ID);
        tmp.Print(input, description);
        size -= tmp.GetSize() + kHeaderSize;
        all_frames.emplace_back(tmp);
    } else {
        Frame tmp(ID);
        tmp.ReadFrame(input, description);
        for (int i = 0; i < tmp.GetSize(); ++i) {
            char ch;
            input.get(ch);
        }
        size -= tmp.GetSize() + kHeaderSize;
    }
}

void MP3::PrintFrames(int size, std::ifstream& input) {
    while (size > 0) {
        char ch;
        std::string ID;
        for (int i = 0; i < 4; ++i) {
            input.get(ch);
            ID += ch;
        }
        PrintFrame(size, input, ID);
    }
}

