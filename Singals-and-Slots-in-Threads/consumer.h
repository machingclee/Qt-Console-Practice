#ifndef CONSUMER_H
#define CONSUMER_H

#include "timer.h"
#include <QDebug>
#include <QObject>
#include <QThread>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);

signals:

public slots:
    void timeout();
    void start();
    void finished();

private:
    QThread thread;
    Timer timer;
};

#endif // CONSUMER_H
