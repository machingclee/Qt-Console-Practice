#ifndef MANAGER_H
#define MANAGER_H

#include "counter.h"
#include <QDebug>
#include <QObject>
#include <QThread>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void start();

signals:

public slots:
    void started();
    void finished();

private:
    QList<QThread*> threads;
};

#endif // MANAGER_H
