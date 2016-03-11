#include "service.h"
#include <iostream>

Service::Service(QObject* parent)
    : QObject(parent)
{

}

Service::~Service()
{

}

QString Service::ping()
{
    std::cout << "ping() called !" << std::endl;
    return "pong";
}
