#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QByteArray>
#include "ekran.h"
#include "math.h"
#include <QTimer>
#include <QDebug>
#include "sleeperthread.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p = new Ekran;
    ui->gridLayout_2->addWidget(p,0,0,0,0);

    setWindowTitle("WYSWIETLACZ WIDMOWY");

    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud1200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serial_receive()));

  ui->edit_led_amount->setText(QString::number(p->LED_AMOUNT));
 ui->edit_led_size->setText(QString::number(p->LED_SIZE));
 ui->edit_gap_size->setText(QString::number(p->INNER_RING));
  ui->edit_brush_size->setText(QString::number(p->CHECK_RECT_SIZE));

     if(ui->edit_brush_size->text().toInt()!=p->CHECK_RECT_SIZE) {p->CHECK_RECT_SIZE=ui->edit_brush_size->text().toInt();}



}

MainWindow::~MainWindow()
{
    serial->close();
    delete ui;

}




void MainWindow::on_pushButton_clicked()
{
    if(!serial->isOpen())
    {
        QMessageBox::warning(this , "PORT ERROR ", "Open the port first");
    }
    else
    {

       int i=0;

       QByteArray send_LED_AMOUNT;
       send_LED_AMOUNT.push_back(p->LED_AMOUNT);
        serial->write(send_LED_AMOUNT);



    while(i!=300)
    {
    int led_rows_left=p->LED_AMOUNT/8;
    if(p->LED_AMOUNT%8!=0) led_rows_left++;

    int led_rows_max=p->LED_AMOUNT/8;
    if(p->LED_AMOUNT%8!=0) led_rows_max++;


        for(int k=0;k<led_rows_max;k++)
        {
        int liczba=0;

        QByteArray bytes;
        int bytes_in_row=0;
        if(led_rows_left==1) bytes_in_row=p->LED_AMOUNT%8;
        else bytes_in_row=8;

        if(bytes_in_row==0) bytes_in_row=8;

        for(int j=0;j<bytes_in_row;j++)
        {

            if(this->p->tLed[(8*k)+j][i]) liczba+=pow(2,j);
        }
        led_rows_left--;
        bytes.push_back(liczba);
        serial->write(bytes);
         }
        i++;

    }

    }
}


 void MainWindow:: serial_receive()
 {
     if(!serial->isOpen())
     {

         QMessageBox::warning(this , "PORT ERROR ", "Open the port first");
     }
 }

void MainWindow::on_pushButton_2_clicked()
{

    serial->open(QIODevice::ReadWrite);
    if(!serial->isOpen())
    {

        QMessageBox::warning(this , "PORT ERROR ", "Could not open the port");
    }
    else
    {
        ui->pushButton_2->setStyleSheet("* { background-color: rgb(100,255,100) }");
    }

}





void MainWindow::on_pushButton_3_clicked()
{
    for(int i=0;i<p->LED_AMOUNT;i++)
    {
     for(int j=0;j<300;j++)
     {
         p->tLed[i][j]=false;

     }
    }

}

void MainWindow::on_pushButton_7_clicked()
{
    bool isResized=false;
   if(ui->edit_led_amount->text().toInt()!=p->LED_AMOUNT &&  ui->edit_led_amount->text().toInt()>0){p->LED_AMOUNT=ui->edit_led_amount->text().toInt();isResized=true;}
   else if (ui->edit_led_amount->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "LED AMOUNT should be greater than 0");
    if(ui->edit_led_size->text().toInt()!=p->LED_SIZE && ui->edit_led_size->text().toInt()>0)  {p->LED_SIZE=ui->edit_led_size->text().toInt();}
     else if (ui->edit_led_size->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "LED SIZE should be greater than 0");
    if(ui->edit_gap_size->text().toInt()!=p->INNER_RING && ui->edit_gap_size->text().toInt()>0) {p->INNER_RING=ui->edit_gap_size->text().toInt();}
     else if (ui->edit_gap_size->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "GAP SIZE should be greater than 0");
    if(ui->edit_brush_size->text().toInt()!=p->CHECK_RECT_SIZE && ui->edit_brush_size->text().toInt()>0) {p->CHECK_RECT_SIZE=ui->edit_brush_size->text().toInt();}
     else if (ui->edit_brush_size->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "BRUSH SIZE should be greater than 0");


    if(isResized==true)
    {
        p->tLed=new bool *[p->LED_AMOUNT];
    for(int i=0;i<p->LED_AMOUNT;i++)
    {
        p->tLed[i]=new bool [300];

    }

    for(int i=0;i<p->LED_AMOUNT;i++)
    {
     for(int j=0;j<300;j++)
     {
        p->tLed[i][j]=false;

     }
    }
    }
}
