#include <QCoreApplication>

#include <iostream>
using namespace std;

#include "mysocket.h"
#include "myhex.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//  myHttp mytest;

    mySocket client;
    client.acceptMessage();

//    myHex hex("dd3");
//    cout << hex.toBinex() <<endl;

    return a.exec();
}
