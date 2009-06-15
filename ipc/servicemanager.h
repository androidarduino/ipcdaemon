#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <QMap>
#include <QList>

typdef Soap QString;

class ServiceManager;

class Client: public QObject
{
    Q_OBJECT
    public:
        Client(QTcpSocket* socket, ServiceManager* parent);
        int send(QString cmd, Soap payload);//send a request to the ipc daemon
    private:
        ulong m_id;
        QTcpSocket* m_socket;
    private slots:
        void readyRead();
    public slots:
        void gotReply(int taskId, Soap result);
};

class Service: public QObject
{
    Q_OBJECT
    public:
        Service();
        void start();
        void kill();
        uint rank();
        bool online;
    private:
        QString executable;
        QString workDir;
        long loadingTime;
        QMap<QString, long> avgAnsTime;
        QMap<QString, long> totalCalled;
};

class ServiceManager: public QObject
{
    Q_OBJECT
    public:
        ServiceManager();
        bool listen(int port);
        static ulong idCount;
    private slots:
        void connected();//when new connection request comes in
        int reg(QString soap);//register a service
        long call(QString svr, QString soap);//call a service application
        void serviceOnline(QString svr);
        void serviceOffline(QString svr);
    private:
        QList<Client*> m_clients;
        QMap<QString, Service*> m_services;
        QTcpServer* server;
};

#endif
