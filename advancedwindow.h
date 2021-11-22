#ifndef ADVANCEDWINDOW_H
#define ADVANCEDWINDOW_H

#include <QMainWindow>


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

};

#endif // ADVANCEDWINDOW_H
