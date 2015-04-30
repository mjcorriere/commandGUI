#ifndef ICOMMAND
#define ICOMMAND

#include <iostream>
#include <QString>
#include <QStringList>

//TODO: Document.

class ICommand {
public:
    ICommand() {}
    virtual void parse(QString args) = 0;
    virtual QString execute() = 0;
};

#endif // ICOMMAND

