#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
{
}

void Counter::start()
{
    for (int i = 0; i < 20; i++)
    {
        qInfo() << QThread::currentThread()->objectName() << "=" << i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(500));
        QThread::currentThread()->msleep(value);
    }

    QThread::currentThread()->quit();
}
