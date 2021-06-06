#include <QCoreApplication>
#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess process;

    process.execute("code");
    process.waitForFinished();
    int exitCode = process.exitCode();

    qInfo() << "exit code:" << exitCode;

    return a.exec();
}
