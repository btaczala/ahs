#include "ApplicationManager.h"
#include "ApplicationEntry.h"

#include <QtCore/QFile>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QProcess>
#include <QtDebug>

ApplicationManager::ApplicationManager(QObject *parent /**/) {}

bool ApplicationManager::launchApplication(const QString &exec,
                                           const QString &directory) {
    const QString path = QString("%1/%2").arg(directory).arg(exec);

    qDebug() << "Launching application " << path;
    return QProcess::startDetached(path, QStringList() << "-platform"
                                                       << "wayland");
}

QObjectList ApplicationManager::registeredApplications() const noexcept {
    return _registeredApplications;
}

void ApplicationManager::setConfigFile(const QString &file) {
    QFile f{file};
    if (!f.exists()) {
        qWarning() << "Config file " << file << " does not exists";
        throw std::runtime_error("Config file does not exists");
    }

    emit registeredApplicationsChanged();

    f.open(QIODevice::ReadOnly);
    auto json = QJsonDocument::fromJson(f.readAll());

    if (json.isNull() || json.isEmpty()) {
        qWarning() << "JSON Document is not valid ";
        throw std::runtime_error("JSON Document is not valid");
    }

    qDebug() << json.isObject() << json.isArray();
    auto rootObject = json.object();

    for (const auto &o : rootObject["applications"].toArray()) {
        const auto currentObject = o.toObject();
        _registeredApplications.append(new ApplicationEntry{currentObject});
    }
}
