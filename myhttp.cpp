#include "myhttp.h"
#include <iostream>


#include <QNetworkRequest>
#include <QByteArray>

using namespace std;

myHttp::myHttp(QObject *parent) : QObject(parent)
{
    QUrl url;
    url.setUrl("http://www.baidu.com/");                  // method 1: construct a url.
//    url.setUrl("http://175.102.134.67:12102");

//    url.setAuthority("http://175.102.134.67:12102");      // method 2: construct a url, no work ?

//    url.setScheme("http");                                  // method 3: construct a url.
//    url.setHost("175.102.134.67");
//    url.setPort(12102);
//    url.setPath("/TJ3N");

    cout << " Is the url available ? " << url.isValid() <<endl;

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    request.setUrl(url);
    request.setRawHeader("User-Agent", "NTRIP MyOwnBrowser 1.0");
    request.setRawHeader("Accept","?*/*");
    request.setRawHeader("Connection","close");
    request.setRawHeader("Authorization","Basic MTAwMDAwMWplcnJ5OmE=");

    reply = manager->get(request);                                    // method 1: get method, default
//    reply = manager->sendCustomRequest(request,"GET /TJ3N HTTP/1.0");   // method 2: get method, custom, no work?
    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
}

void myHttp::replyFinished(QNetworkReply *)
{
    cout << "hello,replyFinished !" << endl;

}

void myHttp::slotReadyRead()
{
    cout << "hello,readyRead ! " << endl;
    cout <<  reply->bytesAvailable() << endl;

    QByteArray recv = reply->readAll();
    cout << recv.toStdString() << endl;

}
