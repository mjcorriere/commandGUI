#ifndef COMMANDFACTORY
#define COMMANDFACTORY

#include <map>
#include "command.h"

class CommandFactory {

public:
    CommandFactory() {}
    Command* buildCommand(std::string);

private:
    std::map<QString, Command*> commandMap;

};

#endif // COMMANDFACTORY

