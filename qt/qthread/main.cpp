#include "thread.h"
#include <QtGui>
#include <QApplication>
#include <QDebug>

void ConsoleThread::run()
{
    char str[256];
    while(true)
    {
        std::cin.getline(str, 255);
        emit textTyped(QString(str));
        qDebug()<<"got line: "<<QString(str);
    }
    //exec();
}


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ConsoleThread thread;
    thread.start();
    QLineEdit edit;
    QApplication::connect(&thread, SIGNAL(textTyped(QString)), &edit, SLOT(setText(QString)));
    edit.show();
    return app.exec();
}
    
