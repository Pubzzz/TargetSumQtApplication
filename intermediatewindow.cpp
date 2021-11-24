#include "intermediatewindow.h"
#include "ui_intermediatewindow.h"
#include <QRandomGenerator>

int c =0;
int s;
int IArray[6];
int nm1,nm2,nm3,nm4,nm5,nm6,tot=0;
IntermediateWindow::IntermediateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntermediateWindow)
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

void IntermediateWindow::mytimer(){
    time = time.addSecs(-1);
    c += 1;
    ui->Timerlbl->setText(time.toString("mm:ss"));
    ui->Statuslbl->setStyleSheet("color: green;");
    ui->Statuslbl->setText("PLAYING");
    if(c == 30){
        ui->Statuslbl->setStyleSheet("color: red;");
        ui->Statuslbl->setText("GAME OVER");
        timer->stop();
        btnDisable();
    }
}

void IntermediateWindow::myRandomNumber(){
    s=0;
    IArray[5]=0;
    int newitem;
    for(int i=0;i<6;i++)
    {
        bool unique;
        do
        {
          unique=true;
          newitem=QRandomGenerator::global()->bounded(10, 50);//Generate number between 1 to 30
          for(int i1=0;i1<i;i1++)
          {
             if(IArray[i1]==newitem)
             {
               unique=false;
                break;
             }
          }
        }while(!unique);
        IArray[i]=newitem;

    }

    for(int i=0; i<3;i++){
        s+=IArray[i];
    }
    ui->Targetlbl->setText(QString::number(s));
    std::random_shuffle(&IArray[0],&IArray[6]);
    ui->btn0->setText(QString::number(IArray[0]));
    ui->btn1->setText(QString::number(IArray[1]));
    ui->btn2->setText(QString::number(IArray[2]));
    ui->btn3->setText(QString::number(IArray[3]));
    ui->btn4->setText(QString::number(IArray[4]));
    ui->btn5->setText(QString::number(IArray[5]));

}


void IntermediateWindow::on_Againbtn_clicked()
{
    tot=0;
    myRandomNumber();
    c = 0;
    ui->Timerlbl->setText("00:30");
    timer->start(1000);
    time.setHMS(0,0,30);
    mytimer();
    btnEnable();
    calculation();
}

void IntermediateWindow::btnDisable(){
    ui->btn0->setEnabled(false);
    ui->btn1->setEnabled(false);
    ui->btn2->setEnabled(false);
    ui->btn3->setEnabled(false);
    ui->btn4->setEnabled(false);
    ui->btn5->setEnabled(false);
}
void IntermediateWindow::btnEnable(){
    ui->btn0->setEnabled(true);
    ui->btn1->setEnabled(true);
    ui->btn2->setEnabled(true);
    ui->btn3->setEnabled(true);
    ui->btn4->setEnabled(true);
    ui->btn5->setEnabled(true);
}
void IntermediateWindow::calculation(){
    if(tot==s){
        ui->Statuslbl->setStyleSheet("color: green;");
        ui->Statuslbl->setText("Congradulations, You Won!!");
        timer->stop();
        btnDisable();
    }
    else if(tot>s){
        ui->Statuslbl->setStyleSheet("color: red;");
        ui->Statuslbl->setText("Oops,You Lost! Let's try Again");
        timer->stop();
        btnDisable();
    }
}

void IntermediateWindow::on_btn0_clicked()
{
    nm1 = ui-> btn0->text().toInt();
    tot = tot +nm1;
    ui->btn0->setEnabled(false);
    calculation();
}


void IntermediateWindow::on_btn1_clicked()
{
    nm2 = ui->btn1->text().toInt();
    tot = tot +nm2;
    ui->btn1->setEnabled(false);
    calculation();
}


void IntermediateWindow::on_btn2_clicked()
{
    nm3 = ui->btn2->text().toInt();
    tot = tot +nm3;
    ui->btn2->setEnabled(false);
    calculation();
}


void IntermediateWindow::on_btn3_clicked()
{
    nm4 = ui->btn3->text().toInt();
    tot = tot +=nm4;
    ui->btn3->setEnabled(false);
    calculation();
}


void IntermediateWindow::on_btn4_clicked()
{
    nm5 = ui->btn4->text().toInt();
    tot = tot +nm5;
    ui->btn4->setEnabled(false);
    calculation();

}


void IntermediateWindow::on_btn5_clicked()
{
    nm6 = ui->btn5->text().toInt();
    tot = tot +nm6;
    ui->btn5->setEnabled(false);
    calculation();
}

