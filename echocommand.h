#ifndef ECHOCOMMAND
#define ECHOCOMMAND

#include "command.h"

class EchoCommand : public Command {
public:
    EchoCommand() { }
    void parse(QString args);
    void execute();
private:
    QString message;
};

#endif // ECHOCOMMAND

