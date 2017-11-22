
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtWebKit>

int main(int argc, char *argv[]) {
    QGuiApplication app{argc, argv};
    QQmlApplicationEngine engine("qrc:///main.qml");
    return app.exec();
}
