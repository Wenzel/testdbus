#include <QCoreApplication>
#include <QtDBus/QtDBus>
#include "ServiceAdapter.h"
#include "ServiceInterface.h"


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    QDBusConnection connection = QDBusConnection::sessionBus();

    Service* serv = new Service(&app);
    ServiceAdapter* adapter = new ServiceAdapter(serv);

    connection.registerService("org.testdbus.service");
    connection.registerObject("/", adapter);

    org::testdbus::service* iface = new org::testdbus::service("org.testdbus.service", "/", connection, &app);

    app.exec();

    return 0;
}

