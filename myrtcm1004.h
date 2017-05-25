#ifndef MYRTCM1004_H
#define MYRTCM1004_H

#include "myrtcm3.h"


class myRTCM1004 : public myRTCM3
{
public:
    myRTCM1004();

    virtual void decodeRTCM3() const;

protected:
    rtcm1004 msg1004;
};

#endif // MYRTCM1004_H
