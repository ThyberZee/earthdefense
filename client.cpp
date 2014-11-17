#include <QTcpSocket>
#include <QDebug>
#include "client.h"

//singleton magic
Client Client::instance;

Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
}

void Client::connectToServer(QString ip)
{
    socket->connectToHost(ip, 5000);
    if (!socket->waitForConnected())  {
        qDebug() << "cannot connect";
        return;
    }

    qDebug() << "connected to server!";
}

void Client::sendMessage(QString msg){
    msg += "\n";
    socket->write(msg.toLocal8Bit());
}

QString Client::getMessage(){
    QString temp = message;
    message = "";
    return temp;
}


/* * * * * * *
 *   SLOTS   *
 * * * * * * */

void Client::dataReceived() {
    while (socket->canReadLine()) {
        message += socket->readLine();
    }
}

void Client::serverDisconnected()
{
    qDebug() << "Client: server disconnected!";
}
