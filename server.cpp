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

    if (!connection.registerService("org.testdbus.service"))
        qFatal("Unable to register");

    if (!connection.registerObject("/", adapter))
        qFatal("unable to object");

    // org::testdbus::service* iface = new org::testdbus::service("org.testdbus.service", "/", connection, &app);

    app.exec();

    return 0;
}

