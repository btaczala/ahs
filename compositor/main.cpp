#include <QtCore/QDebug>
#include <QtCore/QUrl>

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include <QtCore/QCommandLineOption>
#include <QtCore/QCommandLineParser>

#include "ApplicationManager.h"
#include "Controller.h"

int main(int argc, char *argv[]) {
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QGuiApplication app{argc, argv};
    QGuiApplication::setApplicationName("ahs-compositor");
    QGuiApplication::setApplicationVersion("0.1");


    QCommandLineParser parser;
    parser.addHelpOption();

    QCommandLineOption configFile{
        QStringList() << "c"
                      << "configFile",
        QCoreApplication::translate("main", "config file path"),
        QCoreApplication::translate("main", "config")};
    parser.addOption(configFile);

    parser.process(app);

    const QString configFilePath = parser.value(configFile);

    qDebug() << "Config file = " << configFilePath;

    qmlRegisterType<ApplicationManager>("ahs.Compositor.ApplicationManager", 1,
                                        0, "ApplicationManager");

    QQmlApplicationEngine appEngine;
    ApplicationManager appManager;
    Controller ctrl;
    if (!configFilePath.isEmpty()) {
        appManager.setConfigFile(configFilePath);
    }

    appEngine.rootContext()->setContextProperty("controller", &ctrl);
    appEngine.rootContext()->setContextProperty("appManager", &appManager);
    appEngine.rootContext()->setContextProperty(
        "registeredApplications",
        QVariant::fromValue(appManager.registeredApplications()));
    appEngine.load(QUrl("qrc:///qml/main.qml"));

    return app.exec();
}
