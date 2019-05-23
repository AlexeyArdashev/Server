#include <QCoreApplication>
#include "myserver.h"
#include <iostream>
using std::cin;
using std::cout;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int numberPort;
    cout<<"Enter number port: ";cin>>numberPort;
    MyServer server(numberPort);
    return a.exec();
}
