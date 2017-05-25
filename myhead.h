#ifndef MYHEAD
#define MYHEAD

#include <string>
#include <vector>
using namespace std;

struct structRtcmFrame{
    unsigned char         preamble;          // 8 bits,11010011 (0xD3, -45)
    unsigned char         reserved;          // 6 bits,not defined -- set to 000000
    unsigned int          nMsgLen;           // 10 bits,message length in bytes
    unsigned int          nMsgID;            // 12 bits,message type
    unsigned char* msgBuf[1024];            // 0-1023 bytes, variable length data message
    unsigned char* crcBuf[3];               // 24 bits, QualComm definition CRC-24Q
};

struct rtcm1004Header{
    unsigned int msgID;              // DF002, uint12, 12 bits
    unsigned int staID;              // DF003, uint12, 12 bits
    unsigned int TOW;                // DF004, uint30, 30 bits
    unsigned int flagGPSSyn;         // DF005, bit(1), 1 bits
    unsigned int numGPSProcessed;    // DF006, uint5, 5 bits
    unsigned int indicatorGPSSmooth; // DF007, bit(1), 1 bits
    unsigned int intervalGPSSmooth;  // DF008, bit(3), 3 bits
};

struct rtcm1004Body{
    unsigned int GPSID;                    // DF009, uint6, 6 bits
    unsigned int indicatorL1Code;          // DF010, bit(1), 1 bits
    unsigned int L1Pseud;                  // DF011, uint24, 24 bits
             int L1Phase_L1Pseud;          // DF012, int20, 20 bits
    unsigned int L1LockTime;               // DF013, uint7, 7 bits
    unsigned int IntegerPseudAmbiguity_L1; // DF014, uint8, 8 bits
    unsigned int L1CNR;                    // DF015, uint8, 8 bits
    unsigned int indicatorL2Code;          // DF016, bit(2), 2 bits
             int L2_L1PseudDiff;           // DF017, int14, 14 bits
             int L2Phase_L1Pseud;          // DF018, int20, 20 bits
    unsigned int L2LockTime;               // DF019, uint7, 7 bits
    unsigned int L2CNR;                    // DF020, uint8, 7 bits
};

struct rtcm1004{
    rtcm1004Header        header;
    vector<rtcm1004Body>  record;
};

// the below one struct just for rtcm3-class
struct rtcm3{
    unsigned char         preamble;          // 8 bits,11010011 (0xD3, -45)
    unsigned char         reserved;                // 6 bits,not defined -- set to 000000
    unsigned int          nMsgLen;           // 10 bits,message length in bytes
    unsigned int          nMsgID;            // 12 bits,message type
    vector<unsigned char> msgBuf;            // 0-1023 bytes, variable length data message
    vector<unsigned char> crcBuf;            // 24 bits, QualComm definition CRC-24Q
};

#endif // MYHEAD

