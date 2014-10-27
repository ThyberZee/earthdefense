#include "server.h"


void Server::clientConnected(){
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, &MainWindow::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, &MainWindow::dataReceived);
}

void Server::dataReceived(){
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
}

void Server::clientDisconnected(){
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    //--connectCount;
}
