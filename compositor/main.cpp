#include <QtCore/QUrl>

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include "ApplicationManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app{argc, argv};

    qmlRegisterType<ApplicationManager>("ahs.Compositor.ApplicationManager", 1, 0, "ApplicationManager");

    QQmlApplicationEngine appEngine(QUrl("qrc:///qml/main.qml"));

    return app.exec();
}
