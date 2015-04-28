#include "commandfactory.h"
#include "echocommand.h"

Command* CommandFactory::buildCommand() {

    return new EchoCommand();

}
