#include "beginnerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeginnerWindow B;
    B.resize(700,700);
    B.show();
    return a.exec();
}
