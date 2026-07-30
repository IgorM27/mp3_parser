#pragma once

#include "ID3_Header.h"
#include "ExtendHeader.h"
#include "Frame.h"

#include "TextFrame.h"
#include "URLFrame.h"
#include "UFID.h"
#include "TXXX.h"
#include "COMM.h"
#include "COMR.h"
#include "ENCR.h"
#include "EQU2.h"
#include "ETCO.h"
#include "GRID.h"
#include "LINK.h"
#include "OWNE.h"
#include "PCNT.h"
#include "POPM.h"
#include "POSS.h"
#include "PRIV.h"
#include "RBUF.h"
#include "RVA2.h"
#include "SEEK.h"
#include "SYLT.h"
#include "USER.h"
#include "USLT.h"


class MP3 {
public:
    MP3();

    ID3_Header header;
    ExtendHeader extend_header;
    std::vector<Frame> all_frames;

    void PrintFrame(int& size, std::ifstream& input, const std::string& ID);

    void PrintFrames(int size, std::ifstream& input);

    std::unordered_map<std::string, std::string> description;
private:
    const int kHeaderSize = 10;
    const int kIDSize = 4;
};
