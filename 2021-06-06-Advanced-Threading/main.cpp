#include <QCoreApplication>

#include "test.h"
#include <QDateTime>
#include <QDebug>
#include <QSharedPointer>
#include <QThread>

static QSharedPointer<QThread> sharedThreadPtr;

void timeout()
{
    qInfo() << "Time out - stopping other thread from" << QThread::currentThread();
    sharedThreadPtr.data()->quit();
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Current Thread:" << QThread::currentThread();

    Test test;
    qInfo() << "Timer Thread:" << test.thread();

    QThread thread;

    sharedThreadPtr.reset(&thread);
    test.moveToThread(&thread);

    qInfo() << "Timer Thread:" << test.thread();

    test.start();
    thread.start();

    QTimer timer;

    //    quit the thread specified in static shared pointer
    timer.singleShot(5000, &timeout);

    return a.exec();
}
