#include <iostream>

#include <QFileDialog>
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

void CommandGUI::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, "Open Command File", ".", "*.txt");
    ui->fileNameText->setText(fileName);
}

void CommandGUI::on_pushButton_clicked()
{
    std::cout << "building a new command" << std::endl;
    Command* ec = commandFactory->buildCommand();
    std::cout << "command built" << std::endl;
    ec->execute();
}
