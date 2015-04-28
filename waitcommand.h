#ifndef WAITCOMMAND
#define WAITCOMMAND

#include "command.h"

class WaitCommand : public Command {
public:
    WaitCommand() { }
    void parse(QString args);
    void execute();
private:
    int waitTime;
};

#endif // WAITCOMMAND

