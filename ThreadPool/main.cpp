#include "counter.h"
#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThreadPool* pool = QThreadPool::globalInstance();

    qInfo() << pool->maxThreadCount() << "Threads";

    for (int i = 0; i < 100; i++)
    {
        Counter* counter = new Counter();
        counter->setAutoDelete(true);

        pool->start(counter);
    }

    return a.exec();
}
