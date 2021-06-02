#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFlags>

void list(QDir root)
{
    qInfo() << "--- listing ---";

    QFlags<QDir::Filter> filters(QDir::AllEntries | QDir::NoDotAndDotDot);

    foreach (QFileInfo fileInfo, root.entryInfoList(filters, QDir::Name))
    {
        if (fileInfo.isDir())
        {

            qInfo() << "Dir" << fileInfo.filePath();
        }
        if (fileInfo.isFile())
        {
            qInfo() << "File" << fileInfo.filePath();
        }

        if (fileInfo.isDir())
        {
            QDir child(fileInfo.filePath());
            qInfo() << "Inspecting" << child.absolutePath();
            list(child);
        }
    }
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();
    list(dir);

    return a.exec();
}
