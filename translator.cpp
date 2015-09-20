#include "translator.h"
#include "quacktranslator.h"

#include <QCoreApplication>
#include <QTranslator>
#include <QDebug>

TranslateRequest::TranslateRequest(Translator *translator, const QString &text)
    : m_translator(translator),
      m_text(text)
{
    qDebug() << "TranslateRequest::TranslateRequest(): " << this;
    QObject::connect( m_translator, &Translator::languageChange, this, &TranslateRequest::onLanguageChange );
}

TranslateRequest::~TranslateRequest()
{
    qDebug() << "TranslateRequest::~TranslateRequest(): " << this;
}

QVariant TranslateRequest::value() const
{
//    return m_text;
    return tr(m_text.toUtf8().constData());
}

void TranslateRequest::onLanguageChange()
{
    qDebug() << "TranslateRequest::onLanguageChange()";
    emit valueChanged();
}

Translator::Translator()
{
    qApp->installEventFilter(this);
}

Translator::~Translator()
{
}

void Translator::emulateLanguageChange()
{
    qDebug() << "Translator::emulateLanguageChange()";
    qApp->installTranslator(new QuackTranslator(this));
}

QObject *Translator::translate(const QString &text)
{
    return new TranslateRequest(this, text);
}

bool Translator::eventFilter(QObject *obj, QEvent *event)
{
//    qDebug() << "Translator::eventFilter()" << event->type();
    if (event->type() == QEvent::LanguageChange) {
        qDebug() << "Translator::eventFilter(): LanguageChange";
        emit languageChange();
    }

    return QObject::eventFilter(obj, event);
}
