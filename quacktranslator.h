#ifndef QUACKTRANSLATOR
#define QUACKTRANSLATOR

#include <QTranslator>

class QuackTranslator: public QTranslator
{
    Q_OBJECT
public:
    QuackTranslator(QObject *parent = 0);
    ~QuackTranslator();

    QString translate(const char *context, const char *sourceText,
                      const char *disambiguation = 0, int n = -1) const;
    bool isEmpty() const;
};

#endif // QUACKTRANSLATOR
