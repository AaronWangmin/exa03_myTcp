#ifndef MYHEX_H
#define MYHEX_H

#include <string>

using namespace std;

class myHex
{
public:
    myHex(const string& str);
    string toBinex();


private:
    string strHex;                  // only include  0~9 and A ~ F ; don't include a ~ f , 0x and H.
    bool isHex(string& str);        //
    string Hex2Binex(string &str);    //
};

#endif // MYHEX_H
