#include <iostream>

#include <QFileDialog>
#include <QTextStream>

#include "commandgui.h"
#include "ui_commandgui.h"

CommandGUI::CommandGUI(QWidget *parent) :
    QWidget(parent), ui(new Ui::CommandGUI), commandFactory(new CommandFactory()) {
    ui->setupUi(this);
}

CommandGUI::~CommandGUI() {
    delete ui;
    delete commandFactory;
}

void CommandGUI::on_browseButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
                this, "Open Command File", ".", "*.txt");
    ui->fileNameText->setText(fileName);
}

void CommandGUI::on_buildWaitButton_clicked() {
    Command* wc = commandFactory->buildCommand("wait");
    std::cout << "Command built" << std::endl;
    wc->execute();
}

void CommandGUI::on_buildEchoButton_clicked() {
    Command* ec = commandFactory->buildCommand("echo");
    std::cout << "Command built" << std::endl;
    ec->execute();
}

void CommandGUI::on_loadCommandsButton_clicked()
{
    QFile commandsFile(ui->fileNameText->text());
    commandsFile.open(QIODevice::ReadOnly);

    QTextStream commandStream(&commandsFile);
    QString commands = commandStream.readAll();
    commandsFile.close();

    ui->outputTextView->setPlainText(commands);
    ui->executeButton->setEnabled(true);

}
