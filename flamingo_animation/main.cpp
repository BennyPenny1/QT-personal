#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/component_test.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
