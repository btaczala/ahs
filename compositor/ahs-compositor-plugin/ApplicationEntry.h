#ifndef APPLICATIONENTRY_H_KACSRNDM
#define APPLICATIONENTRY_H_KACSRNDM

#include <QtCore/QJsonObject>
#include <QtCore/QObject>
#include <QtCore/QUrl>

class ApplicationEntry : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString exec READ exec CONSTANT)
    Q_PROPERTY(QString dir READ dir CONSTANT)
    Q_PROPERTY(QUrl icon READ icon CONSTANT)
   public:
    ApplicationEntry(const QJsonObject& object) : _object(object) {}
    QString name() const noexcept { return _object["name"].toString(); }
    QString exec() const noexcept { return _object["exec"].toString(); }
    QString dir() const noexcept { return _object["dir"].toString(); }
    QUrl icon() const noexcept {
        return QUrl::fromLocalFile(_object["icon"].toString());
    }

   private:
    const QJsonObject _object;
};

#endif /* end of include guard: APPLICATIONENTRY_H_KACSRNDM */
