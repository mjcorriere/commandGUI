#include "commandgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommandGUI w;
    w.show();

    return a.exec();
}
