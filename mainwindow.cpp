#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_btnNewGame_clicked()
{

}

void MainWindow::on_btnLoadGame_clicked()
{

}
void MainWindow::on_rbSinglePlayer_clicked()
{

}

void MainWindow::on_rbMultiplayer_clicked()
{

}

void MainWindow::clientConnected()
{
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, &MainWindow::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, &MainWindow::dataReceived);
}

void MainWindow::dataReceived()
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

void MainWindow::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    --connectCount;
}

