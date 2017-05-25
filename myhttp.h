#ifndef MYHTTP_H
#define MYHTTP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class myHttp : public QObject
{
    Q_OBJECT
public:
    explicit myHttp(QObject *parent = 0);

signals:

public slots:
    void replyFinished(QNetworkReply*);
    void slotReadyRead();
private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
};

#endif // MYHTTP_H
