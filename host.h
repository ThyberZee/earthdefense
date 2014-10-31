#ifndef HOST_H
#define HOST_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <string>

class Host : public QObject
{
    Q_OBJECT

private:
    QTcpServer* server;
    QTcpSocket* socket;
    int connectCount;
    bool client;
    string message;

public:
    explicit Host(QObject *parent = 0);

signals:

public slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();
    void changeClient(bool tempClient){client = tempClient;}
    void on_serverDisconnected();
    void on_connectionSucceeded();
    string getMessage() {return message;}

};

#endif // HOST_H
