#include "host.h"
#include <QDebug>
Host Host::instance;

Host::Host(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Host::dataReceived);
    connect(socket, &QTcpSocket::disconnected, this, &Host::on_serverDisconnected);
    connect(socket, &QTcpSocket::connected, this, &Host::on_connectionSucceeded);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_socketError(QAbstractSocket::SocketError)));
    qDebug() << socket->localPort();
}

bool Host::listen(){
    return server->listen(QHostAddress::Any, 5000);
}

/*
 * signal/slots
 */

void Host::clientConnected()
{
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, &Host::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, &Host::dataReceived);
    ++connectCount;

    qDebug() << QString("connection!");
}

void Host::dataReceived()
{
    message = "";
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());

    qDebug() << "Received data from socket!";
    while (sock->canReadLine()) {
        QString str = sock->readLine();
        message += str;
        }
    qDebug() << message;
}

void Host::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    --connectCount;
    player2 = false;
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

