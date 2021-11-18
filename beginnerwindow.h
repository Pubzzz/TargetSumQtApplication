#ifndef BEGINNERWINDOW_H
#define BEGINNERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BeginnerWindow; }
QT_END_NAMESPACE

class BeginnerWindow : public QMainWindow
{
    Q_OBJECT

public:
    BeginnerWindow(QWidget *parent = nullptr);
    ~BeginnerWindow();

private:
    Ui::BeginnerWindow *ui;
};
#endif // BEGINNERWINDOW_H
