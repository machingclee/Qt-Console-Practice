#ifndef TEST_H
#define TEST_H

#include <QDebug>
#include <QObject>
#include <QThread>

class Test : public QThread
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void quit();

protected:
    void run();

private:
    bool ok;
};

#endif // TEST_H
