#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTime>
#include <QImage>
#include <QRadioButton>


#define PI 3.14159265359
#define LED_ROWS 120




class Ekran : public QWidget
{
    Q_OBJECT
public:
    explicit Ekran(QWidget *parent = 0);

    bool isClickedLeft=0;
    bool isClickedRight=0;
    bool isPosChanged=0;
    bool isPaintChanged=0;


     int currentX=0;
     int currentY=0;

 int LED_SIZE= 4; //6
 int INNER_RING= 6;//podane w ilosci ledow
 int LED_AMOUNT =30; // 15
 int CHECK_RECT_SIZE= 50;//6
 int ROTATION_ANGLE=0;


     bool **tLed;
     unsigned char **tLed_Green;
     unsigned char **tLed_Red;
     unsigned char **tLed_Blue;

     unsigned char Red=0;
     unsigned char Green=0;
     unsigned char Blue=0;



signals:

public slots:
void paintEvent(QPaintEvent *event);
void generuj_Pedzel(QPainter *d);
void rysuj_Pedzel(QPainter *d);
void rysuj_Tlo(QPainter *d);

 void get_button(const int G, const int R, const int B);


 void mousePressEvent(QMouseEvent *event);
 void mouseReleaseEvent(QMouseEvent *event);
 void mouseMoveEvent(QMouseEvent *event);


};

#endif // EKRAN_H
