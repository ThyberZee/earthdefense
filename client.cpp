#include <QTcpSocket>
#include <QDebug>
#include "client.h"

Client Client::instance;

Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));

}

void Client::connectToServer()
{
    socket->connectToHost("localhost", 5000);
    if (!socket->waitForConnected())  {
        qDebug() << "cannot connect";
        return;
    }

    qDebug() << "connected to server!";
}

void Client::sendMessage(QString msg){
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
    message = "";
    while (socket->canReadLine()) {
        message += socket->readLine();
    }
    qDebug() << message;
}

void Client::serverDisconnected()
{
    qDebug() << "disconnected!";
}
