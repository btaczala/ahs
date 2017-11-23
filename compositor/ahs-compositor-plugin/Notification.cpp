#include "Notification.h"

NotificationWrapper::NotificationWrapper(const Notification& no,
                                         QObject* parent)
    : QObject(parent), _notification(no) {}

QString NotificationWrapper::appName() const noexcept {
    return QString::fromStdString(_notification._appName);
}
