#include "quacktranslator.h"

#include <QDebug>

QuackTranslator::QuackTranslator(QObject *parent)
{
    qDebug() << "QuackTranslator::QuackTranslator()";
}

QuackTranslator::~QuackTranslator()
{
    qDebug() << "QuackTranslator::~QuackTranslator()";
}

QString QuackTranslator::translate(const char *context, const char *sourceText, const char *disambiguation, int n) const
{
    return QString("Quack: ") + sourceText;
}

bool QuackTranslator::isEmpty() const
{
    return false;
}
