#ifndef ADVANCEDWINDOW_H
#define ADVANCEDWINDOW_H

#include <QMainWindow>
//#include "intermediatewindow.h"
//#include "beginnerwindow.h"
#include <QTimer>
#include <QTime>

namespace Ui {
class AdvancedWindow;
}

class AdvancedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdvancedWindow(QWidget *parent = 0);
    ~AdvancedWindow();
public slots:
    void mytimer();
    void myRandomNumber();
    void btnDisable();
    void btnEnable();
    void calculation();

private slots:
    void on_actionBeginner_triggered();

    void on_actionIntermediate_triggered();

    void on_Againbtn_clicked();

    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

private:
    Ui::AdvancedWindow *ui;
//    IntermediateWindow *intermediateWindow;
//    BeginnerWindow *beginnerWindow;
    QTimer *timer;
    QTime time;

};

#endif // ADVANCEDWINDOW_H
