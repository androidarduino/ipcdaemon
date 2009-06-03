#include <QApplication>
#include <QTcpServer>
#include "servicemanager.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ServiceManager manager;
    manager.listen(9312);
    return app.exec();
}
