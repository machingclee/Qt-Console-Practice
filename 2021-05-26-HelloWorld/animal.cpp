#include "animal.h"

animal::animal(QObject* parent)
    : QObject(parent)
{
    qInfo() << "Animal Constructed";
}

animal::~animal()
{
    qInfo() << "Animal Deconstructed";
}
