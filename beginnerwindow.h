#ifndef BEGINNERWINDOW_H
#define BEGINNERWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class BeginnerWindow; }
QT_END_NAMESPACE

class BeginnerWindow : public QMainWindow
{
    Q_OBJECT

public:
    BeginnerWindow(QWidget *parent = 0);
    ~BeginnerWindow();

public slots:
     void mytimer();
     void myRandomNumber(int rangeStart,int rangeEnd);
     void btnDisable();
     void btnEnable();
     void calculation();
     void ResetColor();

private slots:
    void on_actionIntermediate_triggered();

    void on_actionAdvanced_triggered();

    void on_Againbtn_clicked();

    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_actionBeginner_triggered();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();


private:
    Ui::BeginnerWindow *ui;
    QTimer *timer;
    QTime time;
};
#endif // BEGINNERWINDOW_H
