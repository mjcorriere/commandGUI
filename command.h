#ifndef COMMAND
#define COMMAND

#include <iostream>
#include <QString>

//TODO: Document.

class Command {
public:
    Command() {}
    virtual void parse(QString args) = 0;
    virtual void execute() = 0;
};

#endif // COMMAND

