#include "myhex.h"

#include <iostream>
#include <map>
#include <set>

using namespace std;
#include <QDebug>

myHex::myHex(const string& str)
{
    string temp = str;
    if( isHex(temp) )
        strHex = temp;
}

bool myHex::isHex(string& str)
{
    set<string> setHex {"0","1","2","3","4","5","6","7","8","9",
                        "A","B","C","D","E","F",
                        "a","b","c","d","e","f"};

    for(unsigned int i = 0; i < str.length(); i++){
        string s = str.substr(i,1);
        if(!( setHex.count(s))){         // include non-hex letters.
            cout << " string include non-hex letters ! " << endl;
            return false;
        }
                                                       // deal with the valid hex string.
        if(str[i] >= 'a' && str[i] <= 'f'){             // transfer the lower to upper.
            str[i] = str[i] -32;
        }
    }
    return true;
}

string myHex::toBinex()
{
   return Hex2Binex(strHex);
}

string myHex::Hex2Binex(string &str)      //  0~9,A~F TO HEX
{
    map<string,string> mapH2B {
        {"0","0000"},
        {"1","0001"},
        {"2","0010"},
        {"3","0011"},
        {"4","0100"},
        {"5","0101"},
        {"6","0110"},
        {"7","0111"},
        {"8","1000"},
        {"9","1001"},
        {"A","1010"},
        {"B","1011"},
        {"C","1100"},
        {"D","1101"},
        {"E","1110"},
        {"F","1111"},
    };
    map<string,string>::iterator it;

    string strBinex;
    for(unsigned int i = 0; i < str.size(); i++){
        it = mapH2B.find(str.substr(i,1));
        if( it != mapH2B.end() ){
          strBinex += (it->second);
        }
    }

    return strBinex;
}

