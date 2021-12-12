#include "beginnerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeginnerWindow B;
    B.resize(460,530);
    B.show();
    return a.exec();
}
