#ifndef TIMER_H
#define TIMER_H

#include <QDebug>
#include <QObject>
#include <QThread>

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);
    void setInterval(int value);

signals:
    void timeout();

public slots:
    void started();

private:
    int interval = 1000;
};

#endif // TIMER_H
