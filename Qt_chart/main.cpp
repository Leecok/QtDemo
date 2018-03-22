#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.generateRandomData(5, 10, 10);
    w.show();

    return a.exec();
}
