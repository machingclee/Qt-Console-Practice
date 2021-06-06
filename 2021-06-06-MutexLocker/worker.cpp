#include "worker.h"

Worker::Worker(QObject* parent, Counter* counter, QRecursiveMutex* mutex)
    : QObject(parent)
{
    this->counter = counter;
    this->mutex = mutex;
}

void Worker::run()
{
    for (int i = 0; i < 100; i++)
    {
        QMutexLocker locker(mutex);
        counter->increase();
        qInfo() << "Count: " << counter->count();
        counter->decrease();
    }
}
