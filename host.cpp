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
    message = "";
    // Commenting these two lines out for now
    /*
    QString str = sock->readLine();
    message += str;
    */
}

void Host::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    --connectCount;
}

void Host::on_serverDisconnected()
{
     if(client){

     }else{
         player2 = true;
     }
}

void Host::on_connectionSucceeded()
{
    //handle when connection is successful
}

