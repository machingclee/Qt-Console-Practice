#include "QThreadPool"
#include "counter.h"
#include "worker.h"
#include <QCoreApplication>
#include <QDebug>
#include <QRecursiveMutex>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThreadPool* pool = QThreadPool::globalInstance();
    Counter counter;
    QRecursiveMutex mutex;

    for (int i = 0; i < pool->maxThreadCount(); i++)
    {
        Worker* worker = new Worker(&a, &counter, &mutex);
        worker->setAutoDelete(true);
        pool->start(worker);
    }

    pool->waitForDone();
    qInfo() << "Completed, the count is: " << counter.count();

    return a.exec();
}
