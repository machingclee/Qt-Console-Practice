#ifndef STATION_H
#define STATION_H

#include <QDebug>
#include <QObject>

class Station : public QObject {
    Q_OBJECT
public:
    explicit Station(QObject* parent = nullptr, int channel = 0, QString name = "unknown");
    int channel;
    QString name;
signals:
    void send(int channel, QString name, QString message);

public slots:
    void broadcast(QString message);
};

#endif // STATION_H
