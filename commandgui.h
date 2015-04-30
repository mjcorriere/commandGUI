#ifndef COMMANDGUI_H
#define COMMANDGUI_H

#include <QWidget>
#include <QQueue>
#include "commandfactory.h"

namespace Ui {
class CommandGUI;
}

class CommandGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CommandGUI(QWidget *parent = 0);
    ~CommandGUI();

private slots:
    void on_browseButton_clicked();
    void on_loadCommandsButton_clicked();
    void on_executeButton_clicked();

private:
    Ui::CommandGUI *ui;
    CommandFactory *commandFactory;
    QQueue<QString> commandQueue;

};

#endif // COMMANDGUI_H
