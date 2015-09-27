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
    d->setBrush(QColor(this->Red,this->Green,this->Blue));
    d->setPen(QColor(this->Red,this->Green,this->Blue));
    for(int i=0;i<LED_AMOUNT;i++)
    {
     for(int j=0;j<LED_ROWS;j++)
     {
    if(this->tLed[i][j]==true)
    {
        const QPoint next_point(this->maximumHeight()/2+2*(LED_SIZE*(i+INNER_RING-1)*qCos(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS))
                                ,this->maximumHeight()/2+2*(LED_SIZE*(i-1+INNER_RING)*qSin(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS)));
        d->setBrush(QColor(this->tLed_Red[i][j],this->tLed_Green[i][j],this->tLed_Blue[i][j]));
        d->setPen(QColor(this->tLed_Red[i][j],this->tLed_Green[i][j],this->tLed_Blue[i][j]));
         d->drawEllipse(next_point,LED_SIZE,LED_SIZE);
    }

     }
    }
}
void Ekran::rysuj_Tlo(QPainter *d)
{
    d->setBrush(Qt::white);
    d->setPen(Qt::darkMagenta);
    d->drawRect(0,0,this->maximumWidth()-1,this->maximumHeight()-1);
   const QPoint center(this->maximumWidth()/2,this->maximumHeight()/2);//srodek
  //d->drawEllipse(center,LED_SIZE*(2*LED_AMOUNT+INNER_RING),LED_SIZE*(2*LED_AMOUNT+INNER_RING));//obwod
  //d->drawEllipse(center,LED_SIZE*INNER_RING,LED_SIZE*INNER_RING);//wewnetrzny


    d->setPen(Qt::black);
    d->setBrush(Qt::black);
 for(int j=0;j<LED_ROWS;j++)
 {
  for(int i=INNER_RING;i<LED_AMOUNT+INNER_RING;i++)//ledy
  {
      const QPoint next_point(this->maximumHeight()/2+2*(LED_SIZE*(i-1)*qCos(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS)),this->maximumHeight()/2+2*(LED_SIZE*(i-1)*qSin(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS)));
    //if(j%1==0)
       d->drawEllipse(next_point,LED_SIZE,LED_SIZE);
  }
}
}


void Ekran::generuj_Pedzel(QPainter *d) //kat 6*(i+(5/6 zadanego kata))/5 -> dobre przyblizenie
{

    if(this->isPosChanged)
    {
            d->setBrush(Qt::blue);
            d->setPen(Qt::blue);

            QRect checkRect(this->currentX-CHECK_RECT_SIZE,this->currentY-CHECK_RECT_SIZE,2*CHECK_RECT_SIZE,2*CHECK_RECT_SIZE);


            for(int i=0;i<LED_AMOUNT;i++)
            {
             for(int j=0;j<LED_ROWS;j++)
             {
        if(checkRect.contains(this->maximumHeight()/2+2*(LED_SIZE*(i+INNER_RING-1)*qCos(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS))
                ,this->maximumHeight()/2+2*(LED_SIZE*(i-1+INNER_RING)*qSin(360*(j+LED_ROWS/360*90)*PI/180/LED_ROWS))))

            if(this->isClickedLeft)
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



