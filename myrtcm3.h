#ifndef MYRTCM3_H
#define MYRTCM3_H

#include "myhead.h"

class myRTCM3
{
public:
//    myRTCM3();
    void receiveMsg(vector<unsigned char>& rtcm3In);

    virtual ~myRTCM3();
    virtual void decodeRTCM3() const;

    // only test..
    vector<rtcm3>& getRTCM3Msg() const;

protected:
    vector<rtcm3> rtcm3Msg;

private:

    unsigned int crc24Calculated(unsigned char *octests,unsigned int length) const;
    void subByteArray2vector(vector<unsigned char>& destination,
                             const unsigned char* source,
                             int begin,
                             int end) const;

    bool validRTCM3Msg();
};

#endif // MYRTCM3_H
