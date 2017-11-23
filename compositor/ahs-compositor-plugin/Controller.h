#ifndef CONTROLLER_H_JI8RUQH7
#define CONTROLLER_H_JI8RUQH7

#include <QtCore/QObject>
#include <memory>

struct Notification;
class NotificationWrapper;
class Controller : public QObject {
    Q_OBJECT

   public:
    Controller(QObject* parent = nullptr);
    ~Controller();

    void sendNotification(const Notification& n);

   public slots:
    void sendDummyNotification();

   signals:
    void notification(NotificationWrapper*);
    void closeNotification(NotificationWrapper*);

   private:
    std::unique_ptr<NotificationWrapper> _notification;
};

#endif /* end of include guard: CONTROLLER_H_JI8RUQH7 */
