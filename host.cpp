#include "host.h"
#include <QDebug>
Host Host::instance;

Host::Host(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
}

bool Host::start(){
    if(server->listen(QHostAddress::Any, 5000)){
        connect(server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
        //qDebug() << server->localPort();
        return true;
    }
    return false;
}

void Host::sendMessage(QString message){
    for (QObject *obj : server->children()) {
        QTcpSocket *anotherSock = dynamic_cast<QTcpSocket*>(obj);
        if (anotherSock != NULL){
            anotherSock->write(message.toLocal8Bit());
        }
    }
}

QString Host::getMessage(){
    QString temp = message;
    message = "";
    return temp;
}



/* * * * * * * * * * *
 *      SLOTS        *
 * * * * * * * * * * */

void Host::clientConnected()
{
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, &Host::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, &Host::dataReceived);
    connect(sock, &QTcpSocket::disconnected, this, &Host::on_serverDisconnected);
    ++connectCount;

    qDebug() << QString("connection!");
}

void Host::dataReceived()
{
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

//handle when connection is lost.
void Host::on_serverDisconnected()
{
    qDebug() << "connection lost";
}

void Host::on_connectionSucceeded()
{
    qDebug() << "conection successful";
}

