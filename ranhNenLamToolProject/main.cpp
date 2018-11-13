#include "ranhnenlammainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ranhNenLamMainWindow w;
    w.show();

    return a.exec();
}
