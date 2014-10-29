#include "host.h"

Host::Host(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    if(client){
        connect(socket, &QTcpSocket::readyRead, this, &Host::dataReceived);
        connect(socket, &QTcpSocket::disconnected, this, &Host::on_serverDisconnected);
        connect(socket, &QTcpSocket::connected, this, &Host::on_connectionSucceeded);
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_socketError(QAbstractSocket::SocketError)));
    }

}

void Host::clientConnected()
{
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, &Host::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, &Host::dataReceived);
    --connectCount;
}

void Host::dataReceived()
{
    if(client){

    }else{
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
}

void Host::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    --connectCount;
}

void Host::on_serverDisconnected()
{
     //handle disconnects
}

void Host::on_connectionSucceeded()
{
    //handle when connection is successful
}

