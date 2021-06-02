#ifndef TEST_H
#define TEST_H

#include <QDebug>
#include <QObject>
#include <QTimer>

class Test : public QObject {
    Q_OBJECT
public:
    explicit Test(QObject* parent = nullptr);

signals:
public slots:
    void timeout();

private:
    QTimer m_timer;
};

#endif // TEST_H
