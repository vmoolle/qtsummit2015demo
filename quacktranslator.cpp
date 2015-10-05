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
//    return QString("Quack: ") + sourceText;
//    QStringList words = src.split(" ");

    QString src(sourceText);
    QString res;
    res.reserve(src.length());

//    qDebug() << "context: " << context << "src: " << src << " src.length(): " << src.length();

    if (QString(context) != "TranslateRequest")
        return QString(sourceText);

    int wordLength = 0;

    for (int i = 0; i <= src.length(); i++) {
        QChar ch;
        bool atEnd = (i == src.length());

        if (atEnd || !(ch = src.at(i)).isLetter()) {
            if (wordLength > 0) {
                QString quack("quack");
                int quacks = 1 + wordLength / quack.length();
                wordLength = 0;

                res += quack.repeated(quacks);
            }

            if (!atEnd)
                res += ch;
        } else {
            wordLength++;
        }
    }

    qDebug() << "res: " << res;
    return res;
}

bool QuackTranslator::isEmpty() const
{
    return false;
}
