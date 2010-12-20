#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QUuid>
#include <QTcpSocket>

typedef IpcSoap QString;

class IpcClient
{
    Q_OBJECT
    public:
        IpcClient();
        QUuid request(QString url, IpcSoap parameters);
        void registerService(QString service);
    public slots:
        sendReply(IpcSoap result, QUuid ticket);
    signals:
        void reply(IpcSoap result, QUuid ticket);
        void requestReceived(IpcSoap parameters, QUuid ticket);
    private:
        void connectIpcDaemon();
        void sendCmd();
        QTcpSocket* socket;
    private slots:
        void readyRead();
};

#endif
