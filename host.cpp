#include "host.h"

Host::Host(QObject *parent) :
    QObject(parent)
{

}

void Host::clientConnected()
{
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, Host::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, Host::dataReceived);
}

void Host::dataReceived()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());

    while (sock->canReadLine()) {
        QString str = sock->readLine();

        // send data to all connected clients
        for (QObject *obj : server->children()) {
            QTcpSocket *anotherSock = dynamic_cast<QTcpSocket*>(obj);
            if (anotherSock != NULL)
                anotherSock->write(str.toLocal8Bit());
        }

    }
}

void Host::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    --connectCount;
}


