#include "servicemanager.h"

ServiceManager::ServiceManager()
{
    connect(server, SIGNAL(newConnection), this, SLOT(connected()));
}

bool ServiceManager::listen(int port)
{
    qDebug()<<port;
    return true;
}

void ServiceManager::connected()
{
    qDebug()<<"new connection requested. ";
    while(server->hasPendingConnections())
    {
        Client* client=new Client(server->nextPendingConnection(), this);
        m_clients<<client;
    }
}

int ServiceManager::reg(QString soap)
{
    qDebug()<<soap;
    return 0;
}

long ServiceManager::call(QString svr, QString soap)
{
    qDebug()<<svr<<soap;
    return 0;
}
