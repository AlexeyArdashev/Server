#include "myserver.h"
#include <ctime>
MyServer::MyServer(int nPort,QObject *parent):
    QTcpServer(parent)
{
    if (listen(QHostAddress::Any,nPort)){
    qDebug()<<"Server is listten.....";

    }
    else {
        qDebug() << "error: "<<errorString();
    }

}

void MyServer::incomingConnection(int handle){
    QTcpSocket *socket=new QTcpSocket(this); // при передаче в конструктор this socket освобождает память?
    socket->setSocketDescriptor(handle);
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));

}

void MyServer::onReadyRead()
{
    // c сокетом можно рабоать как с файлом (наслед)
    QTcpSocket *socket=qobject_cast<QTcpSocket*> (sender()); // получили сигнал в указатель на наш сокет и преобразовали его
    qDebug()<<socket->readAll();
    QString responce= "HTTP/1.1 200 OK\r\n\r\n%1";
    srand( time( 0 ) ); // автоматическая рандомизация
    int random=rand()%(10-1);
    socket->write(responce.arg(random).toUtf8());
    socket->disconnectFromHost(); // ждет когда все данные отосланы и прерыв соед
}

void MyServer::onDisconnected()
{
       QTcpSocket *socket=qobject_cast<QTcpSocket*> (sender()); // получили сигнал в указатель на наш сокет и преобразовали его
    socket->close();
    socket->deleteLater();
}
