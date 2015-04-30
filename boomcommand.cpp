#include "boomcommand.h"

void BoomCommand::parse(QString argString) {
    // No parsing necessary for explosions.
}

QString BoomCommand::execute() {
    QMessageBox boomBox;
    boomBox.setText("BAM POW!");
    boomBox.exec();

    return QString("We exploded");
}
