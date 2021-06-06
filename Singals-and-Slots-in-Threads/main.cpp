#include "consumer.h"
#include <QCoreApplication>
#include <QDebug>
#include <QThread>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Application started on" << QThread::currentThread();

    Consumer consumer;
    consumer.start();

    return a.exec();
}
