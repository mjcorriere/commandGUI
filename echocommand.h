#ifndef ECHOCOMMAND
#define ECHOCOMMAND

#include "icommand.h"

class EchoCommand : public ICommand {
public:
    EchoCommand() { }
    void parse(QString args);
    QString execute();
private:
    QString message;
};

#endif // ECHOCOMMAND

