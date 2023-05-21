#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gamemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<GameModel>("GameModel", 0, 1, "GameModel");
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/guiMinesweeper/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
