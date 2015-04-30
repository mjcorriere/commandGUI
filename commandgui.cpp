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
    ICommand* wc = commandFactory->buildCommand("wait");
    std::cout << "Command built" << std::endl;
    wc->execute();
}

void CommandGUI::on_buildEchoButton_clicked() {
    ICommand* ec = commandFactory->buildCommand("echo");
    std::cout << "Command built" << std::endl;
    ec->execute();
}

void CommandGUI::on_loadCommandsButton_clicked()
{
    QFile commandsFile(ui->fileNameText->text());
    commandsFile.open(QIODevice::ReadOnly);

    QTextStream commandStream(&commandsFile);

    while (!commandStream.atEnd()) {
        QString line = commandStream.readLine();
        commandQueue.enqueue(line);
    }

    commandsFile.close();

    ui->executeButton->setEnabled(true);
}

void CommandGUI::on_executeButton_clicked()
{
    while (!commandQueue.isEmpty()) {
        QString commandString = commandQueue.dequeue();
        QString commandName = commandString.split(" ").at(0);
        ICommand *command = commandFactory->buildCommand(commandName);
        command->parse(commandString);
        QString output = command->execute();

        ui->outputTextView->append(output);

    }
}
