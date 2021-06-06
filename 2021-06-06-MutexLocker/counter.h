#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject* parent = nullptr);
    void increase();
    void decrease();
    int count();
signals:

private:
    int value;
};

#endif // COUNTER_H
