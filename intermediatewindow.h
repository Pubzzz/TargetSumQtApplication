#ifndef INTERMEDIATEWINDOW_H
#define INTERMEDIATEWINDOW_H

#include <QMainWindow>
//#include "beginnerwindow.h"
//#include "advancedwindow.h"

namespace Ui {
class IntermediateWindow;
}

class IntermediateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IntermediateWindow(QWidget *parent = nullptr);
    ~IntermediateWindow();

private slots:
    void on_actionBeginner_triggered();

    void on_actionAdvanced_triggered();

private:
    Ui::IntermediateWindow *ui;
//    BeginnerWindow *beginnerWindow;
//    AdvancedWindow *advancedWindow;
};

#endif // INTERMEDIATEWINDOW_H
