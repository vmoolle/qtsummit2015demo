#ifndef TRANSLATOR
#define TRANSLATOR

#include "activerequest.h"

class TranslateRequest: public AbstractActiveRequest
{
    Q_OBJECT
public:
    ~TranslateRequest();

    QVariant value() const;

private slots:
    void onLanguageChange();

private:
    friend class Translator;
    TranslateRequest(Translator *translator, const QString& text);

    Translator *m_translator;
    QString m_text;
};

class Translator: public AbstractActiveRequestTarget
{
    Q_OBJECT
signals:
    void languageChange();

public:
    Translator();
    ~Translator();

    Q_INVOKABLE void emulateLanguageChange();
    Q_INVOKABLE QObject* translate(const QString& text);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:

};

#endif // TRANSLATOR
