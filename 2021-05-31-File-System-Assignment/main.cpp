#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QIODevice>
#include <QTemporaryFile>
#include <QTextStream>

void readFile(QString filePath)
{
    qInfo() << "trying to open" << filePath;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        qInfo() << "opened" << filePath;
        qInfo() << file.readAll();
        file.close();
    }
    else
    {
        qInfo() << "cannot open";
    }
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "--- Start! ---";

    QTemporaryFile file;
    QString tmpFilePath;
    if (file.open())
    {
        file.read();
        QFileInfo fileInfo(file);
        tmpFilePath = fileInfo.absoluteFilePath();
        qInfo() << "file path:" << tmpFilePath;
        qInfo() << "writing file ...";
        QString data = "Hello World";
        data.toUtf8();
        file.write(data.toLocal8Bit());
        file.flush();
        qInfo() << "closing file";
        file.close();
        qInfo() << "file closed";
    }

    readFile(tmpFilePath);

    return a.exec();
}
