#include "servicemanager.h"

Client::Client(QTcpSocket* socket, ServiceManager* parent)
{
    qDebug()<<socket<<parent;
}

void Client::readyRead()
{

}

void Client::send(QString cmd)
{
    qDebug()<<cmd;
}

