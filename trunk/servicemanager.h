#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <map>
#include <list>

class ServiceManager;

class Client: public QObject
{
    Q_OBJECT
    public:
        Client(QTcpSocket* socket, ServiceManager* parent);
        void send(QString cmd);
    private:
        ulong id;
        QTcpSocket* m_socket;
    private slots:
        void readyRead();
    signals:
        void dataArrived(ulong id, QString data);
        void receive(QString cmd);
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
        std::map<QString, long> avgAnsTime;
        std::map<QString, long> totalCalled;
};

class ServiceManager: public QObject
{
    Q_OBJECT
    public:
        ServiceManager();
        void listen(int port);
        static ulong idCount;
    private slots:
        void connected();
        void disconnected();
        int reg(QString soap);
        long call(QString svr, QString soap);
    private:
        std::list<Client> m_clients;
        std::map<QString, Service> m_services;
        QTcpServer* server;
};

#endif
