#include "ekran.h"
#include <qmath.h>
#include <QRadioButton>




Ekran::Ekran(QWidget *parent) :
    QWidget(parent)
{

    this->setMaximumHeight(600);
    this->setMaximumWidth(600);
    this->setMouseTracking(true);

     this->tLed=new bool *[LED_AMOUNT];
     this->tLed_Green=new unsigned char *[LED_AMOUNT];
     this->tLed_Red=new unsigned char *[LED_AMOUNT];
     this->tLed_Blue=new unsigned char *[LED_AMOUNT];

     for(int i=0;i<LED_AMOUNT;i++)
      {
        this->tLed[i]=new bool [LED_ROWS];
        this->tLed_Green[i]=new unsigned char [LED_ROWS];
        this->tLed_Red[i]=new unsigned char [LED_ROWS];
        this->tLed_Blue[i]=new unsigned char [LED_ROWS];
      }

      for(int i=0;i<LED_AMOUNT;i++)
       {
        for(int j=0;j<LED_ROWS;j++)
        {
            this->tLed[i][j]=false;
            this->tLed_Green[i][j]=0;
            this->tLed_Red[i][j]=0;
            this->tLed_Blue[i][j]=0;

        }
       }


}

void Ekran::mousePressEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
    if(event->buttons() & Qt::LeftButton) this->isClickedLeft=1;
    if(event->buttons() & Qt::RightButton) this->isClickedRight=1;

    }
}

void Ekran::mouseMoveEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
    this->isPosChanged=1;
        this->currentX=event->pos().x();
                this->currentY=event->pos().y();
    }
}

void Ekran::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->rect().contains(event->pos()))
    {
       this->isClickedLeft=0;
         this->isClickedRight=0;
        this->isPosChanged=0;
    }
}

void Ekran::get_button(const int G, const int R, const int B)
{
  this->Red=R;
  this->Green=G;
  this->Blue=B;
}

void Ekran::paintEvent(QPaintEvent *event)
{
    QPainter d(this);
    rysuj_Tlo(&d);
    generuj_Pedzel(&d);
    rysuj_Pedzel(&d);
     this->update();
}

void Ekran::rysuj_Pedzel(QPainter *d)
{
    for(int i=0;i<LED_AMOUNT;i++)
    {
     for(int j=0;j<LED_ROWS;j++)
    {
    if(this->tLed[i][j]==true)
    {
        const QPoint next_point(this->maximumHeight()/2+2*(LED_SIZE*(i+INNER_RING-1)
                    *qCos(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS))
                    ,this->maximumHeight()/2+2*(LED_SIZE*(i-1+INNER_RING)
                     *qSin(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS)));

       d->setBrush(QColor(this->tLed_Red[i][j],this->tLed_Green[i][j]
                          ,this->tLed_Blue[i][j]));
        d->setPen(QColor(this->tLed_Red[i][j],this->tLed_Green[i][j]
                         ,this->tLed_Blue[i][j]));
        d->drawEllipse(next_point,LED_SIZE,LED_SIZE);
    }

    }
    }
}
void Ekran::rysuj_Tlo(QPainter *d)
{
    d->setBrush(Qt::white);
    d->setPen(Qt::black);
    d->drawRect(0,0,this->maximumWidth()-1,this->maximumHeight()-1);
   const QPoint center(this->maximumWidth()/2,this->maximumHeight()/2);//srodek
  d->drawEllipse(center,LED_SIZE*(2*LED_AMOUNT+1.5*INNER_RING)+2,LED_SIZE*(2*LED_AMOUNT+1.5*INNER_RING)+2);//obwod
  d->drawEllipse(center,LED_SIZE*INNER_RING*1.5-2,LED_SIZE*INNER_RING*1.5-2);//wewnetrzny


    //d->setPen(Qt::black);
    //d->setBrush(Qt::white);
 for(int j=0;j<LED_ROWS;j++)
 {
     d->setPen(Qt::black);
     d->setBrush(Qt::white);
  for(int i=INNER_RING;i<LED_AMOUNT+INNER_RING;i++)//ledy
  {
      const QPoint next_point(this->maximumHeight()/2+2*(LED_SIZE*(i-1)
                                 *qCos(j*360/LED_ROWS*PI/180)),
                              this->maximumHeight()/2+2*(LED_SIZE*(i-1)
                                  *qSin(j*360/LED_ROWS*PI/180)));
       d->drawEllipse(next_point,LED_SIZE,LED_SIZE);


       if(this->ROTATION_ANGLE==j*3 && i==LED_AMOUNT+INNER_RING-1)
       {
           d->setBrush(Qt::red);
           d->setPen(Qt::red);
          const QPoint indicator_point (this->maximumHeight()/2+2*(LED_SIZE*(i-1)
                                            *qCos(j*360/LED_ROWS*PI/180))+qCos(j*360/LED_ROWS*PI/180)*18,
                                         this->maximumHeight()/2+2*(LED_SIZE*(i-1)
                                             *qSin(j*360/LED_ROWS*PI/180))+qSin(j*360/LED_ROWS*PI/180)*18);

           d->drawEllipse(indicator_point,5,5);

            const QPointF points[3] = {
               QPointF(next_point.x()+qCos(j*360/LED_ROWS*PI/180)*7.5,
                next_point.y()+qSin(j*360/LED_ROWS*PI/180)*7.5),
               QPointF(indicator_point.x()+qCos((j+90)*360/LED_ROWS*PI/180)*5,
                indicator_point.y()+qSin((j+90)*360/LED_ROWS*PI/180)*5),
                QPointF(indicator_point.x()+qCos((j-90)*360/LED_ROWS*PI/180)*5,
                 indicator_point.y()+qSin((j-90)*360/LED_ROWS*PI/180)*5)
           };
           d->drawConvexPolygon(points, 3);
       }
  }


}

}


void Ekran::generuj_Pedzel(QPainter *d)
{
    if(this->isPosChanged)
    {
            d->setBrush(Qt::blue);
            d->setPen(Qt::blue);

            QRect checkRect(this->currentX-CHECK_RECT_SIZE,
                            this->currentY-CHECK_RECT_SIZE,
                            2*CHECK_RECT_SIZE,2*CHECK_RECT_SIZE);
            for(int i=0;i<LED_AMOUNT;i++)
            {
             for(int j=0;j<LED_ROWS;j++)
             {
        if(checkRect.contains(this->maximumHeight()/2+2*(LED_SIZE*(i+INNER_RING-1)*
            qCos(j*360/LED_ROWS*PI/180)),this->maximumHeight()/2+2*(LED_SIZE*
            (i-1+INNER_RING)*qSin(j*360/LED_ROWS*PI/180))))

            if(this->isClickedLeft && (this->Green!=0
                   || this->Blue!=0 || this->Red!=0))
            {
                this->tLed[i][j]=true;
                this->tLed_Green[i][j]=this->Green;
                 this->tLed_Red[i][j]=this->Red;
                 this->tLed_Blue[i][j]=this->Blue;
            }
             else if(this->isClickedRight)
            {
                this->tLed[i][j]=false;
                this->tLed_Green[i][j]=0;
                 this->tLed_Red[i][j]=0;
                 this->tLed_Blue[i][j]=0;
             }
            }
}
}
}



