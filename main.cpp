#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "utils/command_util.h"

void registerQmlType();
void registerQmlGlobalObject(QQmlApplicationEngine&);

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    registerQmlType();
    registerQmlGlobalObject(engine);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

void registerQmlType()
{

}

void registerQmlGlobalObject(QQmlApplicationEngine &e)
{
    e.rootContext()->setContextProperty("CommandUtil", CommandUtil::instance());
}
