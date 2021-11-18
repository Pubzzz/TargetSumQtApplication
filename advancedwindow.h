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
    explicit AdvancedWindow(QWidget *parent = nullptr);
    ~AdvancedWindow();

private:
    Ui::AdvancedWindow *ui;
};

#endif // ADVANCEDWINDOW_H
