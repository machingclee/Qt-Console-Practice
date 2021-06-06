#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include <QThread>
#include <task.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThread worker;
    worker.setObjectName("Worker Thread");

    qInfo() << "starting Work" << QThread::currentThread();
    //    Task* task = new Task();
    QScopedPointer<Task> t(new Task());
    Task* task = t.data();
    task->moveToThread(&worker);

    worker.connect(&worker, &QThread::started, task, &Task::work);
    worker.start();

    qInfo() << "free to do other things ..." << QThread::currentThread();

    return a.exec();
}
