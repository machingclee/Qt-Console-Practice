#include "test.h"

Test::Test(QObject* parent)
    : QObject(parent)
{
}

const QString& Test::message() const
{
    return _message;
}

void Test::setMessage(const QString& newMessage)
{
    _message = newMessage;
    emit messageChanged(_message);
}
