#ifndef ACTIVEREQUEST
#define ACTIVEREQUEST

#include <QObject>
#include <QVariant>

class AbstractActiveRequest: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value NOTIFY valueChanged)
signals:
    void valueChanged();
public:
    virtual QVariant value() const=0;
};

class AbstractActiveRequestTarget: public QObject
{
    Q_OBJECT
public:
//protected:
//    AbstractActiveRequest* cppOwned(AbstractActiveRequest* request) const;
};

#endif // ACTIVEREQUEST
