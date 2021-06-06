#include "test.h"

Test::Test(QObject* parent)
    : QObject(parent)
{
    counter = 0;
}

void Test::timeout()
{
    counter++;
    qInfo() << "n-th run:" << counter;
    qInfo() << QDateTime::currentDateTime().toString() << "on" << QThread::currentThread();
}

void Test::start()
{
    connect(&this->timer, &QTimer::timeout, this, &Test::timeout);
    timer.setInterval(1000);
    timer.start();
}
