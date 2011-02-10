#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <iostream>

class ConsoleThread:public QThread
{
    Q_OBJECT
    public:
        ConsoleThread(){}
        void run();
    signals:
        void textTyped(QString text);
};
#endif
