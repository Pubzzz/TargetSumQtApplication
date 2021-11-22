#include "advancedwindow.h"
#include "ui_advancedwindow.h"
#include "ui_beginnerwindow.h"


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

void AdvancedWindow::on_actionBeginner_triggered()
{
//    BeginnerWindow *bw = new BeginnerWindow();
//    bw->show();

}


void AdvancedWindow::on_actionIntermediate_triggered()
{
//    intermediateWindow = new IntermediateWindow();
//    intermediateWindow->show();
//    this->hide();

}

