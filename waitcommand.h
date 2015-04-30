#ifndef WAITCOMMAND
#define WAITCOMMAND

#include <QApplication>
#include "icommand.h"

#ifdef Q_OS_WIN
#include <windows.h>
#endif

class WaitCommand : public ICommand {

public:
    WaitCommand() { }
    void parse(QString args);
    QString execute();

private:
    void sleep(int);
    int waitTime;
};

#endif // WAITCOMMAND

