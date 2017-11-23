#ifndef APPLICATIONMANAGER_H_FPNGLJIK
#define APPLICATIONMANAGER_H_FPNGLJIK

#include <QtCore/QObject>
#include <QtCore/QProcess>

#include <experimental/memory>
#include <memory>
#include <vector>

class ApplicationManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObjectList registeredApplications READ registeredApplications
                   NOTIFY registeredApplicationsChanged)
   public:
    ApplicationManager(QObject* parent = nullptr);
    ~ApplicationManager();

    void setConfigFile(const QString& file);

   public slots:
    bool launchApplication(const QString& exec, const QString& directory);
    QObjectList registeredApplications() const noexcept;

    void closeCurrentApp();

   signals:
    void registeredApplicationsChanged();

   private:
    QObjectList _registeredApplications;
    std::vector<std::unique_ptr<QProcess>> _processes;
    std::experimental::observer_ptr<QProcess> _currentProcess;
};

#endif /* end of include guard: APPLICATIONMANAGER_H_FPNGLJIK */
