#include "translator.h"
#include "quack.h"

#include <QQuickView>
#include <QQmlContext>
#include <QtQml>
#include <QJSValue>
#include <QJSEngine>
#include <QGuiApplication>

static QObject* quackSingletontypeProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new Quack;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<Quack>("Cute.Quack", 1, 0, "Quack", &quackSingletontypeProvider);

    QQuickView view;
    Translator translator;
    view.rootContext()->setContextProperty("translator", &translator);
    view.setSource(QUrl("qrc:/main.qml"));

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(600, 400);
    view.show();

    return app.exec();
}
