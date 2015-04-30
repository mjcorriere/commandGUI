#include "waitcommand.h"

void WaitCommand::parse(QString argString) {
    QString waitTime = argString.split(" ").at(1);
    this->waitTime = waitTime.toInt();
}

QString WaitCommand::execute() {

    sleep(this->waitTime);
    QString output = "Waited for " + QString::number(this->waitTime) + " ms";

    return output;
}

void WaitCommand::sleep(int ms) {
    if (ms > 0) {
    #ifdef Q_OS_WIN
        QApplication::processEvents();
        Sleep(uint(ms));
    #else
        nanosleep(null, null);
    #endif
    }
}


