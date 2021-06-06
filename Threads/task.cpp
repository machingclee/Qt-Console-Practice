#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    qInfo() << "constructed" << this << "on" << QThread::currentThread();
}

Task::~Task()
{
    qInfo() << "deconstructed" << this << "on" << QThread::currentThread();
}

void Task::work()
{
    QThread* thread = QThread::currentThread();

    qInfo() << "starting" << thread;

    for (int i = 0; i < 10; i++)
    {
        qInfo() << i << "on" << thread;
    }

    qInfo() << "finished" << thread;
}
