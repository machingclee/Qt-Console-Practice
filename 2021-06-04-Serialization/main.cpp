#include "test.h"
#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

bool saveFile(Test* t, QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QDataStream ds(&file);
    ds.setVersion(QDataStream::Qt_6_0);

    ds << *t;

    file.close();
    return true;
}

bool loadFile(QString filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
        return false;

    QDataStream ds(&file);
    if (ds.version() != QDataStream::Qt_6_0)
    {
        qCritical() << "Bad version";
        file.close();
        return false;
    }

    Test t;
    ds >> t;
    file.close();

    qInfo() << "name" << t.name();
    foreach (QString key, t.map().keys())
    {
        qInfo() << key << ": " << t.map().value(key);
    }
    return true;
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    QString path = "test.txt";

    Test t;
    t.fill();
    if (saveFile(&t, path))
    {
        loadFile(path);
    }

    return a.exec();
}
