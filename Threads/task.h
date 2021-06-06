#ifndef TASK_H
#define TASK_H

#include <QDebug>
#include <QObject>
#include <QThread>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();

signals:

public slots:
    void work();
};

#endif // TASK_H
