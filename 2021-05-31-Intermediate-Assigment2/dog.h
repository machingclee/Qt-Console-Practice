#ifndef TEST_H
#define TEST_H
#include <QDebug>
#include <QObject>

class Dog : public QObject {
    Q_OBJECT
public:
    explicit Dog(QObject* parent = nullptr, QString name = "");
    ~Dog();
    void bark();

signals:
};

#endif // TEST_H
