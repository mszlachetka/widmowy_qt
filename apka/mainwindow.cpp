#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QByteArray>
#include "ekran.h"
#include "math.h"
#include <QTimer>
#include <QDebug>
#include "sleeperthread.h"
#include <QFileDialog>
#include <QFile>
#include <QTime>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p = new Ekran;
    ui->gridLayout_2->addWidget(p,0,0,0,0);

    setWindowTitle("WYSWIETLACZ WIDMOWY");

    MasterSerialPort->setPortName("com3");
    MasterSerialPort->setBaudRate(QSerialPort::Baud2400);
    MasterSerialPort->setDataBits(QSerialPort::Data8);
    MasterSerialPort->setParity(QSerialPort::NoParity);
    MasterSerialPort->setStopBits(QSerialPort::OneStop);
    MasterSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(MasterSerialPort,SIGNAL(readyRead()),this,SLOT(receive_data()));
    connect(MasterSerialPort,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(serial_dc()));

    ui->pushButton_2->setStyleSheet("* { background-color: rgb(255,100,100) }");

     ui->color_label->setStyleSheet("* { background-color: rgb(0,0,0) }");
  ui->edit_led_amount->setText(QString::number(p->LED_AMOUNT));
 ui->edit_led_size->setText(QString::number(p->LED_SIZE));
 ui->edit_gap_size->setText(QString::number(p->INNER_RING));
  ui->edit_brush_size->setText(QString::number(p->CHECK_RECT_SIZE));

     if(ui->edit_brush_size->text().toInt()!=p->CHECK_RECT_SIZE) {p->CHECK_RECT_SIZE=ui->edit_brush_size->text().toInt();}



    QObject::connect(this, SIGNAL(send_button(const int &,const int &,const int &)),
                    p, SLOT(get_button(const int &,const int &,const int &)));

}



MainWindow::~MainWindow()
{
    MasterSerialPort->close();
    delete ui;

}

void MainWindow::serial_dc()
{
    if(MasterSerialPort->isOpen()) MasterSerialPort->close();
   ui->pushButton_2->setStyleSheet("* { background-color: rgb(255,100,100) }");
}


void MainWindow::on_pushButton_clicked()
{
    if(!MasterSerialPort->isOpen())
    {
        QMessageBox::warning(this , "PORT ERROR ", "Open the port first");
    }
    else
    {
        char send;
        send=(255);//ping
        this->MasterSerialPort->flush();
         this->MasterSerialPort->write(&send,1);
           this->MasterSerialPort->flush();

        delay(200);

        int i=0;
        int j=0;
        while(i!=LED_ROWS)
        {
           for(j=0;j<p->LED_AMOUNT;j++)
           {
               send=p->tLed_Green[j][i];//green
               this->MasterSerialPort->flush();
                this->MasterSerialPort->write(&send,1);
                  this->MasterSerialPort->flush();



               send=p->tLed_Red[j][i];//red
               this->MasterSerialPort->flush();
                this->MasterSerialPort->write(&send,1);
                  this->MasterSerialPort->flush();



               send=p->tLed_Blue[j][i];//blue
               this->MasterSerialPort->flush();
                this->MasterSerialPort->write(&send,1);
                  this->MasterSerialPort->flush();



           }
           delay(200);
            i++;
        }

    }
   /*    int i=0;

       QByteArray send_check;
       send_check.push_back('L');
        serial->write(send_check);

       QByteArray send_LED_AMOUNT;
       send_LED_AMOUNT.push_back(p->LED_AMOUNT);
        serial->write(send_LED_AMOUNT);

    while(i!=LED_ROWS)
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

    }*/
}

void MainWindow::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}


 void MainWindow:: serial_receive()
 {
     if(!MasterSerialPort->isOpen())
     {

         QMessageBox::warning(this , "PORT ERROR ", "Open the port first");
     }
 }



void MainWindow::on_pushButton_2_clicked()
{

    MasterSerialPort->open(QIODevice::ReadWrite);
    if(!MasterSerialPort->isOpen())
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
        setWindowTitle("WYSWIETLACZ WIDMOWY");
    for(int i=0;i<p->LED_AMOUNT;i++)
    {
     for(int j=0;j<LED_ROWS;j++)
     {
         p->tLed[i][j]=false;
          p->tLed_Green[i][j]=0;
           p->tLed_Blue[i][j]=0;
            p->tLed_Red[i][j]=0;

     }
    }

}

void MainWindow::on_pushButton_7_clicked()
{
    bool isResized=false;
   if(ui->edit_led_amount->text().toInt()!=p->LED_AMOUNT &&  ui->edit_led_amount->text().toInt()>0 && ui->edit_led_amount->text().toInt()<=30){p->LED_AMOUNT=ui->edit_led_amount->text().toInt();isResized=true;}
   else if (ui->edit_led_amount->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "LED AMOUNT should be greater than 0");
   else if (ui->edit_led_amount->text().toInt()>30) QMessageBox::warning(this , "WRONG VALUE ", "Maximal LED AMOUNT is 30 ");
    if(ui->edit_led_size->text().toInt()!=p->LED_SIZE && ui->edit_led_size->text().toInt()>0)  {p->LED_SIZE=ui->edit_led_size->text().toInt();}
     else if (ui->edit_led_size->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "LED SIZE should be greater than 0");
    if(ui->edit_brush_size->text().toInt()!=p->CHECK_RECT_SIZE && ui->edit_brush_size->text().toInt()>0) {p->CHECK_RECT_SIZE=ui->edit_brush_size->text().toInt();}
    else if (ui->edit_brush_size->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "BRUSH SIZE should be greater than 0");
    if(ui->edit_gap_size->text().toInt()!=p->INNER_RING && ui->edit_gap_size->text().toInt()>0) {p->INNER_RING=ui->edit_gap_size->text().toInt();}
     else if (ui->edit_gap_size->text().toInt()<=0) QMessageBox::warning(this , "WRONG VALUE ", "GAP SIZE should be greater than 0");


    if(isResized==true)
    {
         setWindowTitle("WYSWIETLACZ WIDMOWY");
        p->tLed=new bool *[p->LED_AMOUNT];
        p->tLed_Green=new unsigned char *[p->LED_AMOUNT];
        p->tLed_Blue=new unsigned char *[p->LED_AMOUNT];
        p->tLed_Red=new unsigned char *[p->LED_AMOUNT];
        for(int i=0;i<p->LED_AMOUNT;i++)
        {
            p->tLed[i]=new bool [LED_ROWS];
             p->tLed_Green[i]=new unsigned char [LED_ROWS];
              p->tLed_Red[i]=new unsigned char [LED_ROWS];
               p->tLed_Blue[i]=new unsigned char[LED_ROWS];
        }

    for(int i=0;i<p->LED_AMOUNT;i++)
    {
     for(int j=0;j<LED_ROWS;j++)
     {
        p->tLed[i][j]=false;
        p->tLed_Green[i][j]=0;
        p->tLed_Blue[i][j]=0;
        p->tLed_Red[i][j]=0;



     }
    }
    }
}

void MainWindow::on_save_Button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("SAVE IMAGE"), "/home/", tr("Images (*.wid)"));

    if(fileName.contains(".wid"))
    {
    QFile mFile(fileName);
    mFile.open(QIODevice::WriteOnly );

    QTextStream mFileData(&mFile);
    mFileData<<"LA"<<"\n"<<p->LED_AMOUNT<<"\n";
    mFileData<<"LS"<<"\n"<<p->LED_SIZE<<"\n";
    mFileData<<"BS"<<"\n"<<p->CHECK_RECT_SIZE<<"\n";
    mFileData<<"GS"<<"\n"<<p->INNER_RING<<"\n";

    for(int j=0;j<LED_ROWS;j++)
        for(int i=0;i<p->LED_AMOUNT;i++)
        {
            mFileData<<p->tLed[i][j];
            if(i==p->LED_AMOUNT-1) mFileData<<"\n";
        }
    for(int j=0;j<LED_ROWS;j++)
        for(int i=0;i<p->LED_AMOUNT;i++)
        {
            mFileData<<p->tLed_Green[i][j]<<"\n";
        }
    for(int j=0;j<LED_ROWS;j++)
        for(int i=0;i<p->LED_AMOUNT;i++)
        {
            mFileData<<p->tLed_Red[i][j]<<"\n";
        }
    for(int j=0;j<LED_ROWS;j++)
        for(int i=0;i<p->LED_AMOUNT;i++)
        {
            mFileData<<p->tLed_Blue[i][j]<<"\n";
        }
     mFile.close();
    }
}

void MainWindow::on_load_Button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("OPEN IMAGE"), "/home/", tr("Images (*.wid);;Images (*.jpg)"));


    bool tflag=true;
    bool gflag=true;
    bool bflag=true;
    bool rflag=true;

    if(fileName.contains(".wid"))
    {
    QFile mFile(fileName);

    mFile.open(QIODevice::ReadOnly );

    setWindowTitle("WYSWIETLACZ WIDMOWY ("+fileName+")");
    QTextStream mFileData(&mFile);
  QString line;

         while (!mFileData.atEnd())
         {

           line= mFileData.readLine();

            if(line.contains("LA"))
            {
                line=mFileData.readLine();
                p->LED_AMOUNT=line.toInt();

                p->tLed=new bool *[p->LED_AMOUNT];
                p->tLed_Green=new unsigned char *[p->LED_AMOUNT];
                p->tLed_Blue=new unsigned char *[p->LED_AMOUNT];
                p->tLed_Red=new unsigned char *[p->LED_AMOUNT];
                for(int i=0;i<p->LED_AMOUNT;i++)
                {
                    p->tLed[i]=new bool [LED_ROWS];
                     p->tLed_Green[i]=new unsigned char [LED_ROWS];
                      p->tLed_Red[i]=new unsigned char [LED_ROWS];
                       p->tLed_Blue[i]=new unsigned char[LED_ROWS];
                }
            }
            else if(line.contains("LS"))
            {
                line=mFileData.readLine();
                p->LED_SIZE=line.toInt();
            }
            else if(line.contains("BS"))
            {
                line=mFileData.readLine();
                p->CHECK_RECT_SIZE=line.toInt();
            }
            else if(line.contains("GS"))
            {
                line=mFileData.readLine();
                p->INNER_RING=line.toInt();
            }
            else if(tflag==true)
            {
            for(int j=0;j<LED_ROWS;j++)
           {
               if(j!=0) line=mFileData.readLine();
                for(int i=0;i<p->LED_AMOUNT;i++)
                {
                   if(line.at(i)=='0') p->tLed[i][j]=false;
                   else if(line.at(i)=='1') p->tLed[i][j]=true;
                }

            }
        tflag=false;
         }
            else if(gflag==true)
            {
                for(int j=0;j<LED_ROWS;j++)
               {
                    for(int i=0;i<p->LED_AMOUNT;i++)
                    {
                         if(j!=0 || i!=0) line=mFileData.readLine();
                        p->tLed_Green[i][j]=line.toDouble();
                    }
            }
                gflag=false;
         }
           else if(rflag==true)
            {
                for(int j=0;j<LED_ROWS;j++)
               {

                    for(int i=0;i<p->LED_AMOUNT;i++)
                    {
                        if(j!=0 || i!=0) line=mFileData.readLine();
                        p->tLed_Red[i][j]=line.toDouble();

                    }
            }
                rflag=false;
         }
            else if(bflag==true)
            {
                for(int j=0;j<LED_ROWS;j++)
               {

                    for(int i=0;i<p->LED_AMOUNT;i++)
                    {
                        if(j!=0 || i!=0) line=mFileData.readLine();
                        p->tLed_Blue[i][j]=line.toDouble();

                    }
            }
                bflag=false;
         }
         }



    mFile.close();

ui->edit_led_amount->setText(QString::number(p->LED_AMOUNT));
ui->edit_led_size->setText(QString::number(p->LED_SIZE));
ui->edit_gap_size->setText(QString::number(p->INNER_RING));
ui->edit_brush_size->setText(QString::number(p->CHECK_RECT_SIZE));

    }


}

void MainWindow::receive_data()
{
    QByteArray mArray;
    mArray=this->MasterSerialPort->readAll();

}

void MainWindow::on_GreenSlider_valueChanged(int value)
{
    emit send_button(ui->GreenSlider->value(),ui->RedSlider->value(),ui->BlueSlider->value());

    QString mText="*{ background-color: rgb("+QString::number(ui->RedSlider->value())+","
                                            +QString::number(ui->GreenSlider->value())+","
                                            +QString::number(ui->BlueSlider->value())+") }";
    ui->color_label->setStyleSheet(mText);
}

void MainWindow::on_RedSlider_valueChanged(int value)
{
       emit send_button(ui->GreenSlider->value(),ui->RedSlider->value(),ui->BlueSlider->value());
    QString mText="*{ background-color: rgb("+QString::number(ui->RedSlider->value())+","
                                            +QString::number(ui->GreenSlider->value())+","
                                            +QString::number(ui->BlueSlider->value())+") }";
            ui->color_label->setStyleSheet(mText);
}

void MainWindow::on_BlueSlider_valueChanged(int value)
{
       emit send_button(ui->GreenSlider->value(),ui->RedSlider->value(),ui->BlueSlider->value());
    QString mText="*{ background-color: rgb("+QString::number(ui->RedSlider->value())+","
                                            +QString::number(ui->GreenSlider->value())+","
                                            +QString::number(ui->BlueSlider->value())+") }";
            ui->color_label->setStyleSheet(mText);
}
