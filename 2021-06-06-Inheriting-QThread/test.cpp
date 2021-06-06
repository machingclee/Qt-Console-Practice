#include "test.h"

Test::Test(QObject* parent)
    : QThread(parent)
{
}

void Test::quit()
{
    ok = false;
    this->quit();
}

void Test::run()
{
    ok = true;
    for (int i = 0; i < 1000; i++)
    {
        qInfo() << i;
        this->sleep(1);

        if (!ok)
        {
            break;
        }
    }

    qInfo() << "Finished";
}
