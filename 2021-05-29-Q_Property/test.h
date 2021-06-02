#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject {
    Q_OBJECT
    QString _message;

public:
    explicit Test(QObject* parent = nullptr);

    Q_PROPERTY(QString messageHA READ message WRITE setMessage NOTIFY messageChanged);

    const QString& message() const;
    void setMessage(const QString& newMessage);

signals:
    void messageChanged(QString message);
};

#endif // TEST_H
