#include "test.h"
#include "watcher.h"
#include <QCoreApplication>
#include <QVariant>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    Test tester;
    Watcher destination;

    QObject::connect(&tester, &Test::messageChanged, &destination, &Watcher::messageChanged);
    tester.setProperty("messageHA", QVariant("Hello World"));
    tester.setMessage("test");

    return a.exec();
}
