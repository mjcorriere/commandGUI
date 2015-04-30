#include "boomcommand.h"

void BoomCommand::parse(QString argString) {

}

QString BoomCommand::execute() {
//    QMessageBox boomBox;
//    boomBox.setText("BAM POW!");
//    boomBox.setInformativeText("Explody bits everywhere.");
//    boomBox.exec();
    throw(new QString("BAM POW!"));
    return QString("We exploded");
}
