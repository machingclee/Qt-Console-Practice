#ifndef DESTINTATION_H
#define DESTINTATION_H

#include <QDebug>
#include <QObject>

class Destination : public QObject {
    Q_OBJECT
public:
    explicit Destination(QObject* parent = nullptr);

signals:
public slots:
    void mySlot(QString message);
};

#endif // DESTINTATION_H
