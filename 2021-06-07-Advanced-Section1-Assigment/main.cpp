#include <QCoreApplication>
#include <QDir>
#include <QDirIterator>
#include <QFutureSynchronizer>
#include <QtConcurrent>

void readFileName(QString filename)
{
    qInfo() << filename
            << "on: "
            << "\n "
            << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir currDir = QDir::current();
    currDir.cdUp();

    QDirIterator iter(currDir.path(), QDir::Files, QDirIterator::Subdirectories);
    QFutureSynchronizer<void> sync;
    int count = 0;

    while (iter.hasNext())
    {
        QString filename = iter.next();
        QFuture<void> future = QtConcurrent::run(&readFileName, filename);
        sync.addFuture(future);
        count++;
    }

    sync.waitForFinished();

    qInfo() << "Scanning completed," << count << "files were found.";

    return a.exec();
}
