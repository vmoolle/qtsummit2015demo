#include "quack.h"

#include <QCoreApplication>
#include <QDebug>

Quack::Quack(QObject *parent)
    : QObject(parent),
      m_on(false),
      m_quackTranslator(new QuackTranslator(this))
{

}

Quack::~Quack()
{

}

bool Quack::on() const
{
    return m_on;
}

void Quack::setOn(bool on)
{
    qDebug() << "Quack::setOn(): " << on;

    if (m_on == on)
        return;

    m_on = on;

    if (m_on)
        qApp->installTranslator(m_quackTranslator);
    else
        qApp->removeTranslator(m_quackTranslator);

    emit onChanged();
}
