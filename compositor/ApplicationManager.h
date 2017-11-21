#ifndef APPLICATIONMANAGER_H_FPNGLJIK
#define APPLICATIONMANAGER_H_FPNGLJIK

#include <QtCore/QObject>

class ApplicationManager : public QObject {
    Q_OBJECT
   public:
    ApplicationManager(QObject* parent = nullptr);

    public slots:

    bool launchApplication(const QString& exec, const QString& directory);

};

#endif /* end of include guard: APPLICATIONMANAGER_H_FPNGLJIK */
