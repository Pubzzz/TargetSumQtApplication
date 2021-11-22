#include "intermediatewindow.h"
#include "ui_intermediatewindow.h"
#include "ui_beginnerwindow.h"
#include "ui_advancedwindow.h"

IntermediateWindow::IntermediateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntermediateWindow)
{
    ui->setupUi(this);
}

IntermediateWindow::~IntermediateWindow()
{
    delete ui;
}

void IntermediateWindow::on_actionBeginner_triggered()
{

}


void IntermediateWindow::on_actionAdvanced_triggered()
{
//    advancedWindow = new AdvancedWindow();
//    advancedWindow->show();
//    this->hide();
}

