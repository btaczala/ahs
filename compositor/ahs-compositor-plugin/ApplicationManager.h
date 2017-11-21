#ifndef APPLICATIONMANAGER_H_FPNGLJIK
#define APPLICATIONMANAGER_H_FPNGLJIK

#include <QtCore/QObject>
class ApplicationManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObjectList registeredApplications READ registeredApplications
                   NOTIFY registeredApplicationsChanged)
   public:
    ApplicationManager(QObject* parent = nullptr);

    void setConfigFile(const QString& file);

   public slots:
    bool launchApplication(const QString& exec, const QString& directory);
    QObjectList registeredApplications() const noexcept;

   signals:
    void registeredApplicationsChanged();

   private:
    QObjectList _registeredApplications;
};
#endif /* end of include guard: APPLICATIONMANAGER_H_FPNGLJIK */
