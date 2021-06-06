#ifndef COUNTER_H
#define COUNTER_H

#include <QDebug>
#include <QObject>
#include <QRandomGenerator>
#include <QRunnable>
#include <QThread>

class Counter : public QRunnable
{
public:
    void run();
};

#endif // COUNTER_H
