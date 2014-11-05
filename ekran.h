#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTime>
#include <QImage>


#define PI 3.14159265359




class Ekran : public QWidget
{
    Q_OBJECT
public:
    explicit Ekran(QWidget *parent = 0);

    bool isClickedLeft=0;
    bool isClickedRight=0;
    bool isPosChanged=0;

     int currentX=0;
     int currentY=0;

 int LED_SIZE= 6; //6
 int INNER_RING= 3;//podane w ilosci ledow
 int LED_AMMOUNT =16; // 16
 int CHECK_RECT_SIZE= 6;//6

     bool **tLed;



signals:

public slots:
 void paintEvent(QPaintEvent *event);
void generuj_Pedzel(QPainter *d);
void rysuj_Pedzel(QPainter *d);
 void rysuj_Tlo(QPainter *d);


 void mousePressEvent(QMouseEvent *event);
 void mouseReleaseEvent(QMouseEvent *event);
 void mouseMoveEvent(QMouseEvent *event);
};

#endif // EKRAN_H
