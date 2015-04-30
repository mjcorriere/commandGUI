#ifndef COMMANDFACTORY
#define COMMANDFACTORY

#include "icommand.h"

class CommandFactory {

public:
    CommandFactory() {}
    ICommand* buildCommand(QString);
};

#endif // COMMANDFACTORY

