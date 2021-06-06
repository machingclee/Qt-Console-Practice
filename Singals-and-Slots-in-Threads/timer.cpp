#include "timer.h"

Timer::Timer(QObject *parent) : QObject(parent)
{
}

void Timer::setInterval(int value)
{
    interval = value;
}

void Timer::started()
{
    qInfo() << "Timer started on " << QThread::currentThread();
    this->thread()->msleep(interval);
    emit timeout();
}
