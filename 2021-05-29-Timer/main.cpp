#include "test.h"
#include <QByteArray>
#include <QCoreApplication>
#include <QDebug>
int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QString greeting = "hello world";

    QByteArray buffer = greeting.toUtf8();

    qInfo() << "The buffer" << buffer;

    return a.exec();
}
