#ifndef SERVER_H
#define SERVER_H

#include <QTcpSocket>

class Server
{
public slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();

public:
    server();
};

#endif // SERVER_H
