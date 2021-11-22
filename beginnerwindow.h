#ifndef BEGINNERWINDOW_H
#define BEGINNERWINDOW_H

#include <QMainWindow>
#include "intermediatewindow.h"
#include "advancedwindow.h"
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
     void myRandomNumber();
     void btnDisable();

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

private:
    Ui::BeginnerWindow *ui;
    QTimer *timer;
    QTime time;
    IntermediateWindow *intermediateWindow;
    AdvancedWindow *advancedWindow;
};
#endif // BEGINNERWINDOW_H
