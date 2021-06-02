#ifndef TEST_H
#define TEST_H

#include "animal.h"
#include <QDebug>
#include <QObject>

class test : public QObject {
    Q_OBJECT
public:
    explicit test(QObject* parent = nullptr);
    ~test();
    animal* dog;
signals:
};

#endif // TEST_H
