#ifndef HOST_H
#define HOST_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Host : public QObject
{
    Q_OBJECT

private:
    QTcpServer* server;
    int connectCount;
    bool client;

public:
    explicit Host(QObject *parent = 0);

signals:

public slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();
    void changeClient(bool tempClient){client = tempClient;}

};

#endif // HOST_H
