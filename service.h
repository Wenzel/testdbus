#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>

class Service : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.testdbus.service")

public:
    Service(QObject* parent = 0);
    ~Service();

public slots:
    QString ping();
};

#endif // SERVICE_H
