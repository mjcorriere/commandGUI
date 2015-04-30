#include "waitcommand.h"

void WaitCommand::parse(QString argString) {
    QString waitTime = argString.split(" ").at(1);
    this->waitTime = waitTime.toInt();
}

QString WaitCommand::execute() {

    std::cout << "Making people wait" << std::endl;

    sleep(this->waitTime);
    QString output = "Waited for " + QString::number(this->waitTime) + " ms";

    return output;
}

void WaitCommand::sleep(int ms) {

    if (ms > 0) {
        // Remind Qt to process the event queue before we nap
        QApplication::processEvents();
    #ifdef Q_OS_WIN
        Sleep(uint(ms));
    #else
        nanosleep(null, null);
    #endif
    }

}


