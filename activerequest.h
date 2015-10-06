#ifndef ACTIVEREQUEST
#define ACTIVEREQUEST

#include <QObject>
#include <QVariant>

class ActiveRequest: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value NOTIFY valueChanged)
signals:
    void valueChanged();
public:
    virtual QVariant value() const=0;
};

#endif // ACTIVEREQUEST
