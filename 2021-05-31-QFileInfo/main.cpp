#include <QCoreApplication>

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFlags>

void list(QString path)
{
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    list(QDir::tempPath());

    return a.exec();
}
