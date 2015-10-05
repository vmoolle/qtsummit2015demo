#ifndef QUACK
#define QUACK

#include "quacktranslator.h"

class Quack: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool on READ on WRITE setOn NOTIFY onChanged)

signals:
    void onChanged();

public:
    Quack(QObject *parent = 0);
    ~Quack();

    bool on() const;
    void setOn(bool on);

private:
    bool m_on;
    QuackTranslator* m_quackTranslator;
};

#endif // QUACK
