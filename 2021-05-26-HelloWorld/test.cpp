#include "test.h"

test::test(QObject* parent)
    : QObject(parent)
{
    qInfo() << this << "test constructed";
}

test::~test()
{
    qInfo() << this << "test deconstructed";
}
