#ifndef WATCHER_H
#define WATCHER_H

#include <QDebug>
#include <QObject>

class Watcher : public QObject {
    Q_OBJECT
public:
    explicit Watcher(QObject* parent = nullptr);

signals:

public slots:
    void messageChanged(QString message);
};

#endif // WATCHER_H
