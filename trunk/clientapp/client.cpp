#include "client.h"

IpcClient::IpcClient()
{
//setup connection to the server, and register service from this client
    socket=new QTcpSocket(this);
    connectIpcDaemon();
}
QUuid IpcClient::request(QString url, IpcSoap parameters);
{
//generate a guid, request using this ticket, and wait for reply
}
//signal: void reply(IpcSoap result, QUuid);
//when the answer arrives, this signal will be emitted.
void IpcClient::registerService(QString service)
{
//register to provide a service
}
void IpcClient::connectIpcDaemon()
{
//init the connection
    socket->connectToHost("localhost",IPC_PORT);
    if(!socket->waitForConnected())
        qDebug()<<"error connecting to local IPC Daemon.";
}
void IpcClient::readyRead()
{
//slot for receiving from the daemon
}
void IpcClient::sendReply(IpcSoap result, QUuid ticket)
{
//slot to send service result to the daemon
}
void IpcClient::sendCmd()
{
//send a command to the daemon
}

