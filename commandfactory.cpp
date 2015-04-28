#include "commandfactory.h"
#include "echocommand.h"
#include "waitcommand.h"

Command* CommandFactory::buildCommand(std::string commandType) {

    if (commandType == "echo") {
        std::cout << "Building a new Echo Command" << std::endl;
        return new EchoCommand();
    } else if (commandType == "wait") {
        std::cout << "Building a new Wait Command" << std::endl;
        return new WaitCommand();
    } else {
        std::cout << "I should probably throw an exception" << std::endl;
    }

}
