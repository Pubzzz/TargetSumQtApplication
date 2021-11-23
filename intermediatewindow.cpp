#include "intermediatewindow.h"
#include "ui_intermediatewindow.h"

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
    //    this->close();
    //    beginnerWindow = new BeginnerWindow(this);
    //    beginnerWindow->show();
}


void IntermediateWindow::on_actionAdvanced_triggered()
{
//    this->close();
//    advancedWindow = new AdvancedWindow(this);
//    advancedWindow->show();
}

