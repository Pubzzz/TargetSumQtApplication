#include "beginnerwindow.h"
#include "ui_beginnerwindow.h"
#include "intermediatewindow.h"
#include <QRandomGenerator>
#include <algorithm>

 int counter =0;
 int sum;
 int randArray[6];
 int num1,num2,num3,num4,num5,num6,total=0;
BeginnerWindow::BeginnerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BeginnerWindow)
{
    ui->setupUi(this);
    myRandomNumber();

    //Initialize "countdown" label text
    ui->Timerlbl->setText("00:30");

    //Connect timer to slot so it gets updated
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mytimer()));

    //It is started with a value of 1000 milliseconds, indicating that it will time out every second.
    timer->start(1000);
    time.setHMS(0,0,30);

    if(total==sum){
        ui->Statuslbl->setText("Congradulations, You Won!!");
    }

}

BeginnerWindow::~BeginnerWindow()
{
    delete ui;
}


void BeginnerWindow::on_actionIntermediate_triggered()
{
    this->close();
    intermediateWindow = new IntermediateWindow(this);
    intermediateWindow->show();
}

void BeginnerWindow::on_actionAdvanced_triggered()
{
    this->close();
    advancedWindow = new AdvancedWindow(this);
    advancedWindow->show();
}

void BeginnerWindow::mytimer(){
    time = time.addSecs(-1);
    counter += 1;
    ui->Timerlbl->setText(time.toString("mm:ss"));
    ui->Statuslbl->setText("PLAYING");
    if(counter == 30){
        ui->Statuslbl->setText("GAME OVER");
        timer->stop();
        btnDisable();
    }
}

void BeginnerWindow::myRandomNumber(){
    sum=0;
    randArray[5]=0;
    int newitem;
    for(int i=0;i<6;i++)
    {
        bool unique;
        do
        {
          unique=true;
          newitem=QRandomGenerator::global()->bounded(1, 10);//Generate number between 10 to 30
          for(int i1=0;i1<i;i1++)
          {
             if(randArray[i1]==newitem)
             {
               unique=false;
                break;
             }
          }
        }while(!unique);
        randArray[i]=newitem;

    }

    for(int i=0; i<3;i++){
        sum+=randArray[i];
    }
    ui->Targetlbl->setText(QString::number(sum));
    std::random_shuffle(&randArray[0],&randArray[6]);
    ui->btn0->setText(QString::number(randArray[0]));
    ui->btn1->setText(QString::number(randArray[1]));
    ui->btn2->setText(QString::number(randArray[2]));
    ui->btn3->setText(QString::number(randArray[3]));
    ui->btn4->setText(QString::number(randArray[4]));
    ui->btn5->setText(QString::number(randArray[5]));

}

void BeginnerWindow::on_Againbtn_clicked()
{
    myRandomNumber();
    counter = 0;
    ui->Timerlbl->setText("00:30");
    timer->start(1000);
    time.setHMS(0,0,30);
    mytimer();
    ui->btn0->setEnabled(true);
    ui->btn1->setEnabled(true);
    ui->btn2->setEnabled(true);
    ui->btn3->setEnabled(true);
    ui->btn4->setEnabled(true);
    ui->btn5->setEnabled(true);
}


void BeginnerWindow::on_btn0_clicked()
{
    num1 = ui-> btn0->text().toInt();
    total = total +num1;
    ui->btn0->setEnabled(false);

}

void BeginnerWindow::on_btn1_clicked()
{
    num2 = ui->btn1->text().toInt();
    total = total +num2;
    ui->btn1->setEnabled(false);

}

void BeginnerWindow::on_btn2_clicked()
{
    num3 = ui->btn2->text().toInt();
    total = total +num3;
    ui->btn2->setEnabled(false);

}


void BeginnerWindow::on_btn3_clicked()
{
    num4 = ui->btn3->text().toInt();
    total = total +=num4;
    ui->btn3->setEnabled(false);

}


void BeginnerWindow::on_btn4_clicked()
{
    num5 = ui->btn4->text().toInt();
    total = total +num5;
    ui->btn4->setEnabled(false);

}


void BeginnerWindow::on_btn5_clicked()
{
    num6 = ui->btn5->text().toInt();
    total = total +num6;
    ui->btn5->setEnabled(false);

}

void BeginnerWindow::btnDisable(){
    ui->btn0->setEnabled(false);
    ui->btn1->setEnabled(false);
    ui->btn2->setEnabled(false);
    ui->btn3->setEnabled(false);
    ui->btn4->setEnabled(false);
    ui->btn5->setEnabled(false);
}

