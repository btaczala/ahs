#include "Controller.h"
#include "Notification.h"

#include <QtCore/QTimer>

Controller::Controller(QObject* parent) : QObject(parent) {}
Controller::~Controller() {}

void Controller::sendNotification(const Notification& n) {
    _notification.reset(new NotificationWrapper{n});

    emit notification(_notification.get());

    QTimer::singleShot(
        3000, [this]() { emit closeNotification(_notification.get()); });
}

void Controller::sendDummyNotification() {
    sendNotification(Notification{"test_app"});
}
