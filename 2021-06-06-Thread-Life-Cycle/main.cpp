#include "manager.h"
#include <QCoreApplication>
#include <QDebug>
#include <QThread>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    Manager manager;
    manager.start();

    return a.exec();
}
