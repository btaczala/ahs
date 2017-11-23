#include "ApplicationManager.h"
#include "ApplicationEntry.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QProcess>
#include <QtDebug>

ApplicationManager::ApplicationManager(QObject *parent /**/) {}

ApplicationManager::~ApplicationManager() {
    for (const auto &process : _processes) {
        process->terminate();
    }
}

bool ApplicationManager::launchApplication(const QString &exec,
                                           const QString &directory) {
    const QDir execDir{directory};
    QString path;

    if (execDir.isAbsolute()) {
        path = QString("%1/%2").arg(directory).arg(exec);
    } else {
        QDir p = QDir::current();
        p.cd(directory);
        path = QString("%1/%2").arg(p.path()).arg(exec);
    }

    qDebug() << "Launching application " << path;

    auto process = std::make_unique<QProcess>();

    QObject::connect(process.get(), &QProcess::stateChanged, this,
                     [](auto state) { qDebug() << "Process state " << state; });

    process->setProgram(path);
    process->setArguments(QStringList() << "-platform"
                                        << "wayland");
    process->start();
    _processes.push_back(std::move(process));

    return (*(_processes.end() - 1))->state() == QProcess::Running;
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

void ApplicationManager::closeCurrentApp() {
    if (_currentProcess) {
        _currentProcess->terminate();
    }

    _currentProcess.reset();
}
