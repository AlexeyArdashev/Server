#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(int nPort,QObject *parent=0);
   virtual void incomingConnection(int handle); // приходит новый запрос от клиента
public slots:
    void onReadyRead();// соед с сигналом кот испускается с получчением новых пакетов данных
    void onDisconnected();
};

#endif // MYSERVER_H
