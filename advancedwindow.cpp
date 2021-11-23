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

void AdvancedWindow::on_actionBeginner_triggered()
{
//    this->close();
//    beginnerWindow = new BeginnerWindow(this);
//    beginnerWindow->show();
}


void AdvancedWindow::on_actionIntermediate_triggered()
{
//    this->close();
//    intermediateWindow = new IntermediateWindow(this);
//    intermediateWindow->show();

}

