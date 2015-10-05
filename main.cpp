#include "translator.h"

#include <QQuickView>
#include <QQmlContext>
#include <QtQml>
#include <QJSValue>
#include <QJSEngine>
#include <QGuiApplication>

static QObject* quackTranslatorSingletontypeProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new Translator;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<Translator>("Cute.Quack", 1, 0, "QuackTranslator", &quackTranslatorSingletontypeProvider);

    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(400, 300);
    view.show();

    return app.exec();
}
