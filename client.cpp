#include <QtDBus/QtDBus>
#include <QDebug>

int main(int argc, char* argv[])
{
    QDBusConnection connection = QDBusConnection::sessionBus();

    QDBusMessage m = QDBusMessage::createMethodCall("org.freedesktop.FileManager1",
                                                    "/",
                                                    "org.freedesktop.DBus.Peer",
                                                    "GetMachineId");

    QDBusMessage response = QDBusConnection::sessionBus().call(m);

    qDebug() << response.ErrorMessage;

    return 0;
}
