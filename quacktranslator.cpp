#include "quacktranslator.h"

#include <QDebug>

QuackTranslator::QuackTranslator(QObject *parent)
    : QTranslator(parent)
{
    qDebug() << "QuackTranslator::QuackTranslator()";
}

QuackTranslator::~QuackTranslator()
{
    qDebug() << "QuackTranslator::~QuackTranslator()";
}

QString QuackTranslator::translate(const char *context, const char *sourceText, const char *disambiguation, int n) const
{
    Q_UNUSED(disambiguation)
    Q_UNUSED(n)

    QString src(sourceText);
    QString res;
    res.reserve(src.length());

    if (QString(context) != "TranslateRequest")
        return QString(sourceText);

    int wordLength = 0;
    bool wordStartsWithUpperCase = false;

    for (int i = 0; i <= src.length(); i++) {
        QChar ch;
        bool atEnd = (i == src.length());

        if (atEnd || !(ch = src.at(i)).isLetter()) {
            if (wordLength > 0) {
                QString quack("quack");
                int quacks = qMax(wordLength/quack.length(), 1);
                wordLength = 0;

                QString word = quack.repeated(quacks);
                if (wordStartsWithUpperCase)
                    word[0] = word[0].toUpper();

                res += word;
            }

            if (!atEnd)
                res += ch;
        } else {
            if (wordLength == 0)
                wordStartsWithUpperCase = ch.isUpper();

            wordLength++;
        }
    }

    return res;
}

bool QuackTranslator::isEmpty() const
{
    return false;
}
