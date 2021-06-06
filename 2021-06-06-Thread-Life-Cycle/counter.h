#ifndef COUNTER_H
#define COUNTER_H

#include <QDebug>
#include <QObject>
#include <QRandomGenerator>
#include <QThread>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);

signals:

public slots:
    void start();
};

#endif // COUNTER_H
