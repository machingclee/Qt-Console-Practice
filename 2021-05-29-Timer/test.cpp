#include "test.h"

Test::Test(QObject* parent)
    : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout, this, &Test::timeout);
    m_timer.setInterval(1000);
    m_timer.start();
    //    m_timer.stop();
}

void Test::timeout()
{
    qInfo() << "Test";
}
