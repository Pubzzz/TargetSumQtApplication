#include "advancedwindow.h"
#include "ui_advancedwindow.h"
#include <QRandomGenerator>

int count =0;
int sm;
int AArray[10];
int n1,n2,n3,n4,n5,n6,n7,n8,n9,ttl=0;
AdvancedWindow::AdvancedWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdvancedWindow)
{
    ui->setupUi(this);
    myRandomNumber();

    //Initialize "countdown" label text
    ui->Timerlbl->setText("00:20");

    //Connect timer to slot so it gets updated
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mytimer()));

    //It is started with a value of 1000 milliseconds, indicating that it will time out every second.
    timer->start(1000);
    time.setHMS(0,0,20);
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

void AdvancedWindow::mytimer(){

    time = time.addSecs(-1);
    count += 1;
    ui->Timerlbl->setText(time.toString("mm:ss"));
    ui->Statuslbl->setStyleSheet("color: green;");
    ui->Statuslbl->setText("PLAYING");
    if(count == 20){
        ui->Statuslbl->setStyleSheet("color: red;");
        ui->Statuslbl->setText("GAME OVER");
        timer->stop();
        btnDisable();
    }
}

void AdvancedWindow::myRandomNumber(){
    sm=0;
    AArray[9]=0;
    int newitem;
    for(int i=0;i<9;i++)
    {
        bool unique;
        do
        {
          unique=true;
          newitem=QRandomGenerator::global()->bounded(10, 80);//Generate number between 10 to 80
          for(int i1=0;i1<i;i1++)
          {
             if(AArray[i1]==newitem)
             {
               unique=false;
                break;
             }
          }
        }while(!unique);
        AArray[i]=newitem;

    }

    for(int i=0; i<4;i++){
        sm+=AArray[i];
    }
    ui->Targetlbl->setText(QString::number(sm));
    std::random_shuffle(&AArray[0],&AArray[6]);
    ui->btn0->setText(QString::number(AArray[0]));
    ui->btn1->setText(QString::number(AArray[1]));
    ui->btn2->setText(QString::number(AArray[2]));
    ui->btn3->setText(QString::number(AArray[3]));
    ui->btn4->setText(QString::number(AArray[4]));
    ui->btn5->setText(QString::number(AArray[5]));
    ui->btn6->setText(QString::number(AArray[6]));
    ui->btn7->setText(QString::number(AArray[7]));
    ui->btn8->setText(QString::number(AArray[8]));

}



void AdvancedWindow::on_Againbtn_clicked()
{
    ttl=0;
    myRandomNumber();
    count = 0;
    ui->Timerlbl->setText("00:20");
    timer->start(1000);
    time.setHMS(0,0,20);
    mytimer();
    btnEnable();
    calculation();
}

void AdvancedWindow::btnDisable(){
    ui->btn0->setEnabled(false);
    ui->btn1->setEnabled(false);
    ui->btn2->setEnabled(false);
    ui->btn3->setEnabled(false);
    ui->btn4->setEnabled(false);
    ui->btn5->setEnabled(false);
    ui->btn6->setEnabled(false);
    ui->btn7->setEnabled(false);
    ui->btn8->setEnabled(false);
}
void AdvancedWindow::btnEnable(){
    ui->btn0->setEnabled(true);
    ui->btn1->setEnabled(true);
    ui->btn2->setEnabled(true);
    ui->btn3->setEnabled(true);
    ui->btn4->setEnabled(true);
    ui->btn5->setEnabled(true);
    ui->btn6->setEnabled(true);
    ui->btn7->setEnabled(true);
    ui->btn8->setEnabled(true);

}
void AdvancedWindow::calculation(){
    if(ttl==sm){
        ui->Statuslbl->setStyleSheet("color: green;");
        ui->Statuslbl->setText("Congradulations, You Won!!");
        timer->stop();
        btnDisable();
    }
    else if(ttl>sm){
        ui->Statuslbl->setStyleSheet("color: red;");
        ui->Statuslbl->setText("Oops,You Lost! Let's try Again");
        timer->stop();
        btnDisable();
    }
}


void AdvancedWindow::on_btn0_clicked()
{
    n1 = ui-> btn0->text().toInt();
    ttl = ttl +n1;
    ui->btn0->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn1_clicked()
{
    n2 = ui-> btn1->text().toInt();
    ttl = ttl +n2;
    ui->btn1->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn2_clicked()
{
    n3 = ui-> btn2->text().toInt();
    ttl = ttl +n3;
    ui->btn2->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn3_clicked()
{
    n4 = ui-> btn3->text().toInt();
    ttl = ttl +n4;
    ui->btn3->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn4_clicked()
{
    n5 = ui-> btn4->text().toInt();
    ttl = ttl +n5;
    ui->btn4->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn5_clicked()
{
    n6 = ui-> btn5->text().toInt();
    ttl = ttl +n6;
    ui->btn5->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn6_clicked()
{
    n7 = ui-> btn6->text().toInt();
    ttl = ttl +n7;
    ui->btn6->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn7_clicked()
{
    n8 = ui-> btn7->text().toInt();
    ttl = ttl +n8;
    ui->btn7->setEnabled(false);
    calculation();
}


void AdvancedWindow::on_btn8_clicked()
{
    n9 = ui-> btn8->text().toInt();
    ttl = ttl +n9;
    ui->btn8->setEnabled(false);
    calculation();
}

