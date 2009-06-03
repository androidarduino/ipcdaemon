#include "servicemanager.h"

ServiceManager::ServiceManager()
{

}

void ServiceManager::listen(int port)
{
    qDebug()<<port;
}

void ServiceManager::connected()
{

}

void ServiceManager::disconnected()
{

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
