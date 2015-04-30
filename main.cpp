#include "commandgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CommandGUI commandGUI;
    commandGUI.show();

    return app.exec();
}
