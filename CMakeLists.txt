cmake_minimum_required(VERSION 3.23)
project(MP3)

set(CMAKE_CXX_STANDARD 20)

include_directories("include")

add_executable(MP3 main.cpp
        include/parser.h src/parser.cpp include/Frame.h src/Frame.cpp include/ID3_Header.h src/ID3_Header.cpp include/UFID.h src/UFID.cpp include/TextFrame.h src/TextFrame.cpp include/TXXX.h src/TXXX.cpp include/URLFrame.h src/URLFrame.cpp include/WXXX.h src/WXXX.cpp include/ETCO.h src/ETCO.cpp include/USLT.h src/USLT.cpp include/SYLT.h src/SYLT.cpp include/COMM.h src/COMM.cpp include/RVA2.h src/RVA2.cpp include/EQU2.h src/EQU2.cpp include/PCNT.h src/PCNT.cpp include/POPM.h src/POPM.cpp include/RBUF.h src/RBUF.cpp include/LINK.h src/LINK.cpp include/POSS.h src/POSS.cpp include/USER.h src/USER.cpp include/OWNE.h src/OWNE.cpp include/COMR.h src/COMR.cpp include/ENCR.h src/ENCR.cpp include/GRID.h src/GRID.cpp include/PRIV.h src/PRIV.cpp include/SEEK.h src/SEEK.cpp include/ExtendHeader.h src/ExtendHeader.cpp include/MP3.h src/MP3.cpp)
