#ifndef ADVANCEDWINDOW_H
#define ADVANCEDWINDOW_H

#include <QMainWindow>
//#include "intermediatewindow.h"
//#include "beginnerwindow.h"

namespace Ui {
class AdvancedWindow;
}

class AdvancedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdvancedWindow(QWidget *parent = 0);
    ~AdvancedWindow();

private slots:
    void on_actionBeginner_triggered();

    void on_actionIntermediate_triggered();

private:
    Ui::AdvancedWindow *ui;
//    IntermediateWindow *intermediateWindow;
//    BeginnerWindow *beginnerWindow;
};

#endif // ADVANCEDWINDOW_H
