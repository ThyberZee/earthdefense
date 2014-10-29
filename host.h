#ifndef HOST_H
#define HOST_H

#include <QObject>

class Host : public QObject
{
    Q_OBJECT

private:
    QTcpServer* server;
    int connectCount;

public:
    explicit Host(QObject *parent = 0);

signals:

public slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();

};

#endif // HOST_H
