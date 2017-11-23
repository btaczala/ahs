#ifndef NOTIFICATION_H_TNAY0V8Q
#define NOTIFICATION_H_TNAY0V8Q

#include <QtCore/QObject>

struct Notification {
    std::string _appName;
};

class NotificationWrapper : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString appName READ appName CONSTANT);

   public:
    NotificationWrapper(const Notification& n, QObject* parent = nullptr);

    QString appName() const noexcept;

   private:
    const Notification _notification;
};

#endif /* end of include guard: NOTIFICATION_H_TNAY0V8Q */
