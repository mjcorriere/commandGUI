#include <iostream>

#include <QFileDialog>
#include <QMessageBox>
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

void CommandGUI::on_loadCommandsButton_clicked()
{
    ui->outputTextView->clear();

    QFile commandsFile(ui->fileNameText->text());

    if (commandsFile.open(QIODevice::ReadOnly)) {

        QTextStream commandStream(&commandsFile);

        while (!commandStream.atEnd()) {
            QString line = commandStream.readLine();
            commandQueue.enqueue(line);
        }

        commandsFile.close();

        ui->executeButton->setEnabled(true);

    } else {
        QMessageBox messageBox;
        messageBox.setText("Coule not open file.");
        messageBox.exec();
    }
}

void CommandGUI::on_executeButton_clicked()
{
    while (!commandQueue.isEmpty()) {

        QString commandString = commandQueue.dequeue();
        QString commandName = commandString.split(" ").at(0);

        ICommand *command = commandFactory->buildCommand(commandName);

        if (command != NULL) {
            command->parse(commandString);
            QString output = command->execute();

            ui->outputTextView->append(output);
        }

    }

    ui->executeButton->setEnabled(false);

}
