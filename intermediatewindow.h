#ifndef INTERMEDIATEWINDOW_H
#define INTERMEDIATEWINDOW_H

#include <QMainWindow>
//#include "beginnerwindow.h"
//#include "advancedwindow.h"
#include <QTimer>
#include <QTime>

namespace Ui {
class IntermediateWindow;
}

class IntermediateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IntermediateWindow(QWidget *parent = nullptr);
    ~IntermediateWindow();

public slots:
    void mytimer();
    void myRandomNumber();
    void btnDisable();
    void btnEnable();
    void calculation();

private slots:
    void on_actionBeginner_triggered();

    void on_actionAdvanced_triggered();

    void on_Againbtn_clicked();

    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

private:
    Ui::IntermediateWindow *ui;
//    BeginnerWindow *beginnerWindow;
//    AdvancedWindow *advancedWindow;
    QTimer *timer;
    QTime time;
};

#endif // INTERMEDIATEWINDOW_H
