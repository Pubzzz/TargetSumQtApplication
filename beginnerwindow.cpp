#include "beginnerwindow.h"
#include "ui_beginnerwindow.h"

BeginnerWindow::BeginnerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BeginnerWindow)
{
    ui->setupUi(this);
}

BeginnerWindow::~BeginnerWindow()
{
    delete ui;
}

