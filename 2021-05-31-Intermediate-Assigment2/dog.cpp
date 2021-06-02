#include "dog.h"

Dog::Dog(QObject* parent, QString name)
    : QObject(parent)
{
    this->setObjectName(name);
    qInfo() << "dog" << this->objectName() << "is constructed";
}

void Dog::bark()
{
    qInfo() << "dog"
            << this->objectName()
            << "used bark,"
            << "super effective.";
}

Dog::~Dog()
{
    qInfo() << "dog" << this->objectName() << "is destroyed";
}
