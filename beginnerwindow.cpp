#include "beginnerwindow.h"
#include "ui_beginnerwindow.h"
#include <QRandomGenerator>

//Declaring global variables
 int counter =0;
 int sum;
 int randArray[6];
 int num1,num2,num3,num4,num5,num6,total=0;

BeginnerWindow::BeginnerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BeginnerWindow)
{
    ui->setupUi(this);
    ui->Levellbl->setText("Beginner Level");
    ui->Levellbl->setStyleSheet("color: green;");
    //Calling method to generate Random number and display it to the UI
    myRandomNumber(1,10);

    //Initialize "countdown" label text
    ui->Timerlbl->setText("00:30");

    //Connect timer to mytimer slot so it gets updated
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mytimer()));

    //It is started with a value of 1000 milliseconds, indicating that it will time out every second.
    timer->start(1000);
    time.setHMS(0,0,30);
}

BeginnerWindow::~BeginnerWindow()
{
    delete ui;
}

void BeginnerWindow::on_actionBeginner_triggered()
{
    ui->Levellbl->setText("Beginner Level");
    ui->Levellbl->setStyleSheet("color: green;");
    myRandomNumber(1,10);
}

void BeginnerWindow::on_actionIntermediate_triggered()
{
    ui->Levellbl->setText("Intermediate Level");
    ui->Levellbl->setStyleSheet("color: blue;");
    myRandomNumber(1,30);
}

void BeginnerWindow::on_actionAdvanced_triggered()
{
    ui->Levellbl->setText("Advanced Level");
    ui->Levellbl->setStyleSheet("color: red;");
    myRandomNumber(10,80);
}

void BeginnerWindow::mytimer(){
    //updates time
    time = time.addSecs(-1);
    counter += 1;
    ui->Timerlbl->setText(time.toString("mm:ss"));
    ui->Statuslbl->setStyleSheet("color: green;");
    ui->Statuslbl->setText("PLAYING");
    if(counter == 30){
        ui->Statuslbl->setStyleSheet("color: red;");
        ui->Statuslbl->setText("GAME OVER");
        timer->stop();
        //Disables the pushbuttons
        btnDisable();
    }
}

void BeginnerWindow::myRandomNumber(int rangeStart,int rangeEnd){
    sum=0;
    randArray[5]=0;
    int newitem;
    //Generates an array of distinct numbers
    for(int i=0;i<6;i++)
    {
        bool unique;
        do
        {
          unique=true;
          newitem=QRandomGenerator::global()->bounded(rangeStart, rangeEnd);//Generate number between 1 to 10
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
    //Gets the sum of the first three array values
    for(int i=0; i<3;i++){
        sum+=randArray[i];
    }
    //Assign the sum to the Targetlbl
    ui->Targetlbl->setText(QString::number(sum));
    //Shuffles the order of elements in the array
    std::random_shuffle(&randArray[0],&randArray[6]);
    //Display array values in the UI pushbuttons
    ui->btn0->setText(QString::number(randArray[0]));
    ui->btn1->setText(QString::number(randArray[1]));
    ui->btn2->setText(QString::number(randArray[2]));
    ui->btn3->setText(QString::number(randArray[3]));
    ui->btn4->setText(QString::number(randArray[4]));
    ui->btn5->setText(QString::number(randArray[5]));

}

void BeginnerWindow::on_Againbtn_clicked()
{
    total=0;
    //Generates a new target number
    myRandomNumber(1,10);
    //Resets the timer
    counter = 0;
    ui->Timerlbl->setText("00:30");
    timer->start(1000);
    time.setHMS(0,0,30);
    mytimer();
    //Enables the pushbuttons
    btnEnable();
    //Calls the calculation function
    calculation();
}


void BeginnerWindow::on_btn0_clicked()
{
    num1 = ui-> btn0->text().toInt();
    total = total +num1;
    ui->btn0->setEnabled(false);
    calculation();
}

void BeginnerWindow::on_btn1_clicked()
{
    num2 = ui->btn1->text().toInt();
    total = total +num2;
    ui->btn1->setEnabled(false);
    calculation();
}

void BeginnerWindow::on_btn2_clicked()
{
    num3 = ui->btn2->text().toInt();
    total = total +num3;
    ui->btn2->setEnabled(false);
    calculation();

}


void BeginnerWindow::on_btn3_clicked()
{
    num4 = ui->btn3->text().toInt();
    total = total +=num4;
    ui->btn3->setEnabled(false);
    calculation();

}


void BeginnerWindow::on_btn4_clicked()
{
    num5 = ui->btn4->text().toInt();
    total = total +num5;
    ui->btn4->setEnabled(false);
    calculation();

}


void BeginnerWindow::on_btn5_clicked()
{
    num6 = ui->btn5->text().toInt();
    total = total +num6;
    ui->btn5->setEnabled(false);
    calculation();

}

void BeginnerWindow::btnDisable(){
    ui->btn0->setEnabled(false);
    ui->btn1->setEnabled(false);
    ui->btn2->setEnabled(false);
    ui->btn3->setEnabled(false);
    ui->btn4->setEnabled(false);
    ui->btn5->setEnabled(false);
}
void BeginnerWindow::btnEnable(){
    ui->btn0->setEnabled(true);
    ui->btn1->setEnabled(true);
    ui->btn2->setEnabled(true);
    ui->btn3->setEnabled(true);
    ui->btn4->setEnabled(true);
    ui->btn5->setEnabled(true);
}
void BeginnerWindow::calculation(){
    //Checks whether the clicked button values are equal to the Target value
    if(total==sum){
        ui->Statuslbl->setStyleSheet("color: green;");
        ui->Statuslbl->setText("Congradulations, You Won!!");
        timer->stop();
        btnDisable();
    }
    else if(total>sum){
        ui->Statuslbl->setStyleSheet("color: red;");
        ui->Statuslbl->setText("Oops,You Lost! Let's try Again");
        timer->stop();
        btnDisable();
    }
}




