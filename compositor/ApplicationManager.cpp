#include "ApplicationManager.h"

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
