#include "translator.h"

#include <QQuickView>
#include <QQmlContext>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;

    Translator translator;
    view.rootContext()->setContextProperty("translator", &translator);

    view.setSource(QUrl("qrc:/main.qml"));

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(400, 300);
    view.show();

    return app.exec();
}
