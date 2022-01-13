 #include "beginnerwindow.h"
#include "ui_beginnerwindow.h"
#include <QRandomGenerator>

//Declaring global variables
 int counter =0;
 int sum;
 int randArray[6];
 int randAdvancedArray[9];
 int num1,num2,num3,num4,num5,num6,num7,num8,num9,total=0;
 int level=1;
 QString clickedStyle="QPushButton {"
                      "background-color:#E0E0E0;"
                      "border-radius:5%;"
                    "}";

BeginnerWindow::BeginnerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BeginnerWindow)
{
    ui->setupUi(this);
    ui->Levellbl->setText("Beginner Level");
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
    level=1;
    timer->stop();
    ui->Levellbl->setText("Beginner Level");
    myRandomNumber(1,10);
    counter = 0;
    ui->Timerlbl->setText("00:30");
    timer->start(1000);
    time.setHMS(0,0,30);
    mytimer();
    //Enables the pushbuttons
    btnEnable();
    //Calls the calculation function
    calculation();
    ResetColor();
}

void BeginnerWindow::on_actionIntermediate_triggered()
{
    level=2;
    timer->stop();
    ui->Levellbl->setText("Intermediate Level");
    myRandomNumber(1,30);
    counter = 0;
    ui->Timerlbl->setText("00:30");
    timer->start(1000);
    time.setHMS(0,0,30);
    mytimer();
    //Enables the pushbuttons
    btnEnable();
    //Calls the calculation function
    calculation();
    ResetColor();
}

void BeginnerWindow::on_actionAdvanced_triggered()
{
    ui->btn6->show();
    ui->btn7->show();
    ui->btn8->show();
    level=3;
    timer->stop();
    ui->Levellbl->setText("Advanced Level");
    myRandomNumber(10,80);
    counter = 0;
    ui->Timerlbl->setText("00:20");
    timer->start(1000);
    time.setHMS(0,0,20);
    mytimer();
    //Enables the pushbuttons
    btnEnable();
    //Calls the calculation function
    calculation();
    ResetColor();
}

void BeginnerWindow::mytimer(){
    //updates time
    time = time.addSecs(-1);
    counter += 1;
    ui->Timerlbl->setText(time.toString("mm:ss"));
    ui->Statuslbl->setStyleSheet("color: black;");
    ui->Statuslbl->setText("PLAYING");
    if(level==1 || level==2){
        if(counter == 30){
            ui->Statuslbl->setStyleSheet("color: red;");
            ui->Statuslbl->setText("GAME OVER");
            timer->stop();
            //Disables the pushbuttons
            btnDisable();
        }
    }
    else{
        if(counter == 20){
                ui->Statuslbl->setStyleSheet("color: red;");
                ui->Statuslbl->setText("GAME OVER");
                timer->stop();
                //Disables the pushbuttons
                btnDisable();
            }
    }
}

void BeginnerWindow::myRandomNumber(int rangeStart,int rangeEnd){
    if(level==1 || level ==2){
    sum=0;
    int newitem;
    //Generates an array of distinct numbers
    for(int i=0;i<6;i++)
    {
        bool unique;
        do
        {
          unique=true;
          newitem=QRandomGenerator::global()->bounded(rangeStart, rangeEnd);//Generate number between the given range
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
    ui->btn6->hide();
    ui->btn7->hide();
    ui->btn8->hide();
    }
    else{
        sum=0;
        int newitem;
        //Generates an array of distinct numbers
        for(int i=0;i<9;i++)
        {
            bool unique;
            do
            {
              unique=true;
              newitem=QRandomGenerator::global()->bounded(rangeStart, rangeEnd);//Generate number between the given range
              for(int i1=0;i1<i;i1++)
              {
                 if(randAdvancedArray[i1]==newitem)
                 {
                   unique=false;
                    break;
                 }
              }
            }while(!unique);
            randAdvancedArray[i]=newitem;

        }
        //Gets the sum of the first three array values
        for(int i=0; i<4;i++){
            sum+=randAdvancedArray[i];
        }
        //Assign the sum to the Targetlbl
        ui->Targetlbl->setText(QString::number(sum));
        //Shuffles the order of elements in the array
        std::random_shuffle(&randAdvancedArray[0],&randAdvancedArray[9]);
        //Display array values in the UI pushbuttons
        ui->btn0->setText(QString::number(randAdvancedArray[0]));
        ui->btn1->setText(QString::number(randAdvancedArray[1]));
        ui->btn2->setText(QString::number(randAdvancedArray[2]));
        ui->btn3->setText(QString::number(randAdvancedArray[3]));
        ui->btn4->setText(QString::number(randAdvancedArray[4]));
        ui->btn5->setText(QString::number(randAdvancedArray[5]));
        ui->btn6->setText(QString::number(randAdvancedArray[6]));
        ui->btn7->setText(QString::number(randAdvancedArray[7]));
        ui->btn8->setText(QString::number(randAdvancedArray[8]));
    }

}

void BeginnerWindow::on_Againbtn_clicked()
{
    if(level==1){
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
    ResetColor();
    }
    else if(level==2){
        total=0;
        //Generates a new target number
        myRandomNumber(1,30);
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
        ResetColor();
    }
    else{
        total=0;
        //Generates a new target number
        myRandomNumber(10,80);
        //Resets the timer
        counter = 0;
        ui->Timerlbl->setText("00:20");
        timer->start(1000);
        time.setHMS(0,0,20);
        mytimer();
        //Enables the pushbuttons
        btnEnable();
        //Calls the calculation function
        calculation();
        ResetColor();
    }
}


void BeginnerWindow::on_btn0_clicked()
{
    num1 = ui-> btn0->text().toInt();
    total = total +num1;
    ui->btn0->setEnabled(false);
    calculation();
    ui->btn0->setStyleSheet(clickedStyle);
}


void BeginnerWindow::on_btn1_clicked()
{
    num2 = ui->btn1->text().toInt();
    total = total +num2;
    ui->btn1->setEnabled(false);
    calculation();
    ui->btn1->setStyleSheet(clickedStyle);
}

void BeginnerWindow::on_btn2_clicked()
{
    num3 = ui->btn2->text().toInt();
    total = total +num3;
    ui->btn2->setEnabled(false);
    calculation();
    ui->btn2->setStyleSheet(clickedStyle);
}


void BeginnerWindow::on_btn3_clicked()
{
    num4 = ui->btn3->text().toInt();
    total = total +=num4;
    ui->btn3->setEnabled(false);
    calculation();
    ui->btn3->setStyleSheet(clickedStyle);

}


void BeginnerWindow::on_btn4_clicked()
{
    num5 = ui->btn4->text().toInt();
    total = total +num5;
    ui->btn4->setEnabled(false);
    calculation();
    ui->btn4->setStyleSheet(clickedStyle);

}


void BeginnerWindow::on_btn5_clicked()
{
    num6 = ui->btn5->text().toInt();
    total = total +num6;
    ui->btn5->setEnabled(false);
    calculation();
    ui->btn5->setStyleSheet(clickedStyle);

}

void BeginnerWindow::btnDisable(){
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
void BeginnerWindow::btnEnable(){
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

void BeginnerWindow::on_btn6_clicked()
{
    num7 = ui->btn6->text().toInt();
    total = total +num7;
    ui->btn6->setEnabled(false);
    calculation();
    ui->btn6->setStyleSheet(clickedStyle);
}


void BeginnerWindow::on_btn7_clicked()
{
    num8 = ui->btn7->text().toInt();
    total = total +num8;
    ui->btn7->setEnabled(false);
    calculation();
    ui->btn7->setStyleSheet(clickedStyle);
}


void BeginnerWindow::on_btn8_clicked()
{
    num9 = ui->btn8->text().toInt();
    total = total +num9;
    ui->btn8->setEnabled(false);
    calculation();
    ui->btn8->setStyleSheet(clickedStyle);
}

void BeginnerWindow::ResetColor(){
    ui->btn0->setStyleSheet("outline: none;");
    ui->btn1->setStyleSheet("outline: none;");
    ui->btn2->setStyleSheet("outline: none;");
    ui->btn3->setStyleSheet("outline: none;");
    ui->btn4->setStyleSheet("outline: none;");
    ui->btn5->setStyleSheet("outline: none;");
    ui->btn6->setStyleSheet("outline: none;");
    ui->btn7->setStyleSheet("outline: none;");
    ui->btn8->setStyleSheet("outline: none;");
}



