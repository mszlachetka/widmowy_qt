#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QByteArray>
#include "ekran.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p = new Ekran;
    ui->gridLayout_2->addWidget(p,0,0,0,0);

    setWindowTitle("WYSWIETLACZ WIDMOWY");
    ui->lineEdit->setMaxLength(3);
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud1200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serial_receive()));



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

   int liczba=ui->lineEdit->text().toInt();
    QByteArray bytes;
    bytes.push_back(liczba);
        serial->write(bytes);

}

 void MainWindow:: serial_receive()
 {
     if(!serial->isOpen())
     {

         QMessageBox::warning(this , "PORT ERROR ", "Open the port first");
     }
     ui->label->setText(serial->readAll());
     BytesRead++;
     QString sBytesRead=QString::number(BytesRead);
     ui->label_4->setText(sBytesRead);
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

void MainWindow::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().toInt()>255) ui->lineEdit->setText("255");
     if(ui->lineEdit->text().toInt()<0) ui->lineEdit->setText("0");
}



void MainWindow::on_pushButton_3_clicked()
{
    for(int i=0;i<p->LED_AMMOUNT;i++)
    {
     for(int j=0;j<360;j++)
     {
         p->tLed[i][j]=false;
     }
    }

}

void MainWindow::on_pushButton_7_clicked()//zmiana paramentrow do poprawy
{
    bool isResized=false;
   if(ui->edit_led_ammount->text().toInt()!=p->LED_AMMOUNT){p->LED_AMMOUNT=ui->edit_led_ammount->text().toInt();isResized=true;}
    if(ui->edit_led_size->text().toInt()!=p->LED_SIZE)  {p->LED_SIZE=ui->edit_led_size->text().toInt();isResized=true;}
    if(ui->edit_gap_size->text().toInt()!=p->INNER_RING) {p->INNER_RING=ui->edit_gap_size->text().toInt();isResized=true;}

    if(ui->edit_brush_size->text().toInt()!=p->CHECK_RECT_SIZE) {p->CHECK_RECT_SIZE=ui->edit_brush_size->text().toInt();}



    if(isResized==true)
    {
        p->tLed=new bool *[p->LED_AMMOUNT];
    for(int i=0;i<p->LED_AMMOUNT;i++)
    {
        p->tLed[i]=new bool [360];
    }


    for(int i=0;i<p->LED_AMMOUNT;i++)
    {
     for(int j=0;j<360;j++)
     {
        p->tLed[i][j]=false;
     }
    }
    }
}
