#ifndef WORKER_H
#define WORKER_H

#include "QRecursiveMutex"
#include "counter.h"
#include <QDebug>
#include <QMutexLocker>
#include <QObject>
#include <QRunnable>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject* parent = nullptr, Counter* counter = nullptr, QRecursiveMutex* mutex = nullptr);
    void run();

signals:
private:
    Counter* counter;
    QRecursiveMutex* mutex;
};

#endif // WORKER_H
