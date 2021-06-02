#ifndef RADIO_H
#define RADIO_H

#include <QDebug>
#include <QObject>

class Radio : public QObject {
    Q_OBJECT
public:
    explicit Radio(QObject* parent = nullptr);

signals:
    void quit();
public slots:
    void listen(int channel, QString name, QString message);
};

#endif // RADIO_H
