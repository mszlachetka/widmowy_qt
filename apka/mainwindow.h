#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>
#include "ekran.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QSerialPort *MasterSerialPort = new QSerialPort(this);
     int BytesRead=0;


private:
    Ui::MainWindow *ui;
    Ekran *p;


public slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void serial_receive();
    void serial_dc();
    void receive_data();


    void delay(int ms);

private slots:

    void on_pushButton_3_clicked();

    void on_save_Button_clicked();
    void on_load_Button_clicked();



    void on_GreenSlider_valueChanged(int value);

    void on_RedSlider_valueChanged(int value);

    void on_BlueSlider_valueChanged(int value);

    void on_lowerButton_clicked();

    void on_upperButton_clicked();

    void on_edit_led_size_editingFinished();

    void on_edit_brush_size_cursorPositionChanged(int arg1, int arg2);




    void on_lineEdit_returnPressed();


signals:
  void  send_button(const int Green, const int Red, const int Blue);
};

#endif // MAINWINDOW_H
