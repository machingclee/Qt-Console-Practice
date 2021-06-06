#include "test.h"
#include <QCoreApplication>
#include <QSharedPointer>
#include <QTimer>

static QSharedPointer<Test> sTestPtr;

void timeout()
{
    if (!sTestPtr.isNull())
    {
        qInfo() << "Timeout, stoping thread";
        sTestPtr.data()->quit();
    }
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    Test thread;

    sTestPtr.reset(&thread);
    thread.start();

    QTimer timer;
    timer.singleShot(5000, &timeout);

    return a.exec();
}
