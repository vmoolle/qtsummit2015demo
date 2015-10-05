#include "translator.h"

#include <QQuickView>
#include <QQmlContext>
#include <QtQml>
#include <QJSValue>
#include <QJSEngine>
#include <QGuiApplication>

static QJSValue quackTranslatorSingletontypeProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)

    static Translator *quackTranslator = new Translator;
    return scriptEngine->newQObject(quackTranslator);
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType("Cute.Quack", 1, 0, "quackTranslator", &quackTranslatorSingletontypeProvider);

    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(400, 300);
    view.show();

    return app.exec();
}
