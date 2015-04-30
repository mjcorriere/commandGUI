#ifndef BOOMCOMMAND
#define BOOMCOMMAND

#include "icommand.h"
#include <QMessageBox>

class BoomCommand : public ICommand {

public:
    BoomCommand() { }
    void parse(QString args);
    QString execute();
};

#endif // BOOMCOMMAND

