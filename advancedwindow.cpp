#include "advancedwindow.h"
#include "ui_advancedwindow.h"

AdvancedWindow::AdvancedWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdvancedWindow)
{
    ui->setupUi(this);
}

AdvancedWindow::~AdvancedWindow()
{
    delete ui;
}
