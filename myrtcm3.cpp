#include "myrtcm3.h"

//myRTCM3::myRTCM3()
//{

//}

void myRTCM3::receiveMsg(vector<unsigned char> &rtcm3In)
{
    vector<unsigned char>::iterator it;
    for(it = rtcm3In.begin(); it != rtcm3In.end(); it++){
        unsigned char cFirst = *it;
        if( 0xD3 == (cFirst & 0xFF) ){          // scan the "preamble" by one char in turn.

            unsigned char cTemp1 = *(++it);
            // check reserved 6 bits == 0, 0xFC = 111111 00
            if( 0 != (cTemp1 & 0xFC) ){
                continue;
            }

            unsigned char cTemp2 = *(++it);
            // read message length
            unsigned int nMsgLen = (cTemp1 & 0x03)*256 + (cTemp2 & 0xFF);

            unsigned char msgBuf[1024];
            msgBuf[0] = cFirst;
            msgBuf[1] = cTemp1;
            msgBuf[2] = cTemp2;

            // read message contents
            for(unsigned int j = 0; j < nMsgLen; j++){
                msgBuf[j+3] = *(++it);
            }

            // read CRC-24 parity
            unsigned char crcBuf[3];
            for(unsigned int j = 0; j < 3; j++){
               crcBuf[j] = *(++it);
            }

            // perform CRC check
            unsigned int crc_calculated = 0;
            crc_calculated = crc24Calculated(msgBuf,nMsgLen + 3);
            if(crc_calculated == (crcBuf[0] << 16) + (crcBuf[1] << 8) + crcBuf[2] ){
                // add the one integrity rtcm message to the vector.
                rtcm3 rtcm3T;       // one rtcm message,such as 1004.
                rtcm3T.preamble = cFirst;
                rtcm3T.reserved = cTemp1;
                rtcm3T.nMsgLen = nMsgLen;
                //rtcm3T.nMsgID = 0;
                vector<unsigned char> vTemp01;
                subByteArray2vector(rtcm3T.msgBuf,msgBuf,3,nMsgLen + 3);
                subByteArray2vector(rtcm3T.crcBuf,crcBuf,0,3);

                rtcm3Msg.push_back(rtcm3T);
            }
        }
    }
}

void myRTCM3::subByteArray2vector(vector<unsigned char>& destination,
                                  const unsigned char* source,
                                  int begin,
                                  int end) const
{
    for(int i = begin; i < end; i++){
        destination.push_back(source[i]);
    }
}

unsigned int myRTCM3::crc24Calculated(unsigned char *octests, unsigned int length) const
{
    unsigned int CRC_INIT = 0x000000;
    unsigned int CRC24_POLY = 0x1864cfb;

    unsigned int crc = CRC_INIT;           // initial to 0
    int i;
    while(length--){
        crc ^= (*octests++) << 16;
        for(i = 0; i < 8; i++){
            crc <<= 1;
            if( crc & 0x1000000) crc ^= CRC24_POLY;
        }
    }
    return crc & 0xFFFFFF;
}

myRTCM3::~myRTCM3()
{

}

void myRTCM3::decodeRTCM3() const
{

}

