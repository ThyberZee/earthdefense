#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>

class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* socket;
    QString message;


public:
    explicit Client(QObject *parent = 0);

    void connectToServer(QString ip);
    QString getMessage();
    void sendMessage(QString msg);
    
signals:
    
public slots:
    void dataReceived();
    void serverDisconnected();


//singleton magic.  I'm waving my hands!
private:
    static Client instance;
public:
    static Client &getInstance() {
        return instance;
    }
    
};

#endif // CLIENT_H
