#ifndef TEST_H
#define TEST_H

#include <QDateTime>
#include <QObject>
#include <QThread>
#include <QTimer>
#include <QtDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject* parent = nullptr);

signals:

public slots:
    void timeout();
    void start();

private:
    int counter;
    QTimer timer;
};

#endif // TEST_H
