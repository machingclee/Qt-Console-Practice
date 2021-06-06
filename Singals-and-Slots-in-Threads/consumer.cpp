#include "consumer.h"

Consumer::Consumer(QObject *parent) : QObject(parent)
{
    qInfo() << "Created on " << QThread::currentThread();
    thread.setObjectName("Timer Thread");

    connect(&timer, &Timer::timeout, this, &Consumer::timeout, Qt::QueuedConnection);
    connect(&thread, &QThread::started, &timer, &Timer::started, Qt::DirectConnection);
    connect(&thread, &QThread::finished, this, &Consumer::finished, Qt::DirectConnection);
}

void Consumer::timeout()
{
    qInfo() << "Consumer timeout on " << QThread::currentThread();
    thread.quit();
}

void Consumer::start()
{
    qInfo() << "Thread started on " << QThread::currentThread();
    timer.setInterval(500);
    timer.moveToThread(&thread);
    thread.start();
}

void Consumer::finished()
{
    qInfo() << "Thread finished on " << QThread::currentThread();
}
