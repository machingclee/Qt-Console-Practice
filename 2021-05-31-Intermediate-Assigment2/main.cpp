#include <QCoreApplication>
#include <QDataStream>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QTextStream>

bool write(QString filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)) {
        qInfo() << file.errorString();
        return false;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_0);

    int age = 45;
    QString name = "James";
    double weight = 185.06;

    stream << age << name << weight;

    qInfo() << "file has been written";

    if (!file.flush()) {
        qInfo() << file.errorString();
        file.close();
        return false;
    }

    qInfo() << "closing file";

    file.close();
    return true;
}

bool read(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qInfo() << file.errorString();
        return false;
    }

    QDataStream stream(&file);

    if (stream.version() != QDataStream::Qt_6_0) {
        qInfo() << "Wrong file version";
        file.close();
        return false;
    }

    int age;
    QString name;
    double weight;

    stream >> age;
    stream >> name;
    stream >> weight;

    file.close();

    qInfo() << "age" << age;
    qInfo() << "name" << name;
    qInfo() << "weight" << weight;

    return true;
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}
