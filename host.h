#ifndef HOST_H
#define HOST_H

#include <QObject>
#include <QTcpServer>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QString>

class Host : public QObject
{
    Q_OBJECT

private:
    QTcpServer* server;
    QTcpSocket* socket;
    int connectCount;
    bool client;
    QString message;
    bool player2;

public:
    explicit Host(QObject *parent = 0);
    bool start();
    QString getMessage() {return message;}
    void sendMessage(QString message);
    bool getPlayer2(){return player2;}

signals:

public slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();
    void on_serverDisconnected();
    void on_connectionSucceeded();


//singleton magic.  I'm waving my hands!
private:
    static Host instance;
public:
    static Host &getInstance() {
        return instance;
    }
};

#endif // HOST_H
