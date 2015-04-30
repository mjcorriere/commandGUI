#include "commandfactory.h"
#include "echocommand.h"
#include "waitcommand.h"
#include "boomcommand.h"

ICommand* CommandFactory::buildCommand(QString commandType) {

    if (commandType == "echo") {
        std::cout << "Building a new Echo Command" << std::endl;
        return new EchoCommand();
    } else if (commandType == "wait") {
        std::cout << "Building a new Wait Command" << std::endl;
        return new WaitCommand();
    } else if (commandType == "boom") {
        std::cout << "Building a new Boom Command" << std::endl;
        return new BoomCommand();
    } else {
        std::cout << "***Command " << commandType.toStdString() << " unknown.***" << std::endl;
        return NULL;
    }

}
