#include "beginnerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeginnerWindow w;
    w.show();
    return a.exec();
}
