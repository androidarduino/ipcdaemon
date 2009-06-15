#include <QTest>
#include "servicemanager.h"

class IPCDaemonTest:public QObject
{
    Q_OBJECT
    public:
    private slots:
        void serviceManagerListen();
};
