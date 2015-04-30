#include <iostream>
#include "echocommand.h"

void EchoCommand::parse(QString argString) {
    QStringList arguments = argString.split(" ").mid(1);
    this->message = arguments.join(" ");
}

QString EchoCommand::execute() {
    std::cout << "Echoing something." << std::endl;
    return this->message;
}

