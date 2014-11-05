#include "ekran.h"
#include <qmath.h>





Ekran::Ekran(QWidget *parent) :
    QWidget(parent)
{

    this->setMaximumHeight(600);
    this->setMaximumWidth(600);
    this->setMouseTracking(true);

    this->tLed=new bool *[LED_AMMOUNT];
    for(int i=0;i<LED_AMMOUNT;i++)
    {
        this->tLed[i]=new bool [360];

    }

   for(int i=0;i<LED_AMMOUNT;i++)
   {
    for(int j=0;j<360;j++)
    {
        this->tLed[i][j]=false;
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



void Ekran::paintEvent(QPaintEvent *event)
{


    QPainter d(this);

        rysuj_Tlo(&d);
        generuj_Pedzel(&d);
        rysuj_Pedzel(&d);


           this->update();
        //this->update(this->currentX,this->currentY,16,16);


       // d.end();
        //const QRect mRect(this->currentX-LED_SIZE,this->currentY-LED_SIZE,LED_SIZE,LED_SIZE);
        //this->update(mRect);
  //  QImage image(this->maximumHeight(),this->maximumWidth(),QImage::Format_ARGB32_Premultiplied);
   // QPainter d(&image);
   // rysuj_Tlo(&d);
   // QPainter widgetPainter(this);
    //widgetPainter.drawImage(0, 0, image);
}

void Ekran::rysuj_Pedzel(QPainter *d)
{
    d->setBrush(Qt::blue);
    d->setPen(Qt::blue);
    for(int i=0;i<LED_AMMOUNT;i++)
    {
     for(int j=0;j<360;j++)
     {
    if(this->tLed[i][j]==true)
    {
        const QPoint next_point(this->maximumHeight()/2+2*(LED_SIZE*(i+INNER_RING-1)*qCos(j*PI/180)),this->maximumHeight()/2+2*(LED_SIZE*(i-1+INNER_RING)*qSin(j*PI/180)));

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
  //d->drawEllipse(center,LED_SIZE*(2*LED_AMMOUNT+INNER_RING),LED_SIZE*(2*LED_AMMOUNT+INNER_RING));//obwod
  //d->drawEllipse(center,LED_SIZE*INNER_RING,LED_SIZE*INNER_RING);//wewnetrzny


    d->setPen(Qt::red);
 for(int j=0;j<360;j++)
 {
  for(int i=INNER_RING;i<LED_AMMOUNT+INNER_RING;i++)//ledy
  {
      const QPoint next_point(this->maximumHeight()/2+2*(LED_SIZE*(i-1)*qCos(j*PI/180)),this->maximumHeight()/2+2*(LED_SIZE*(i-1)*qSin(j*PI/180)));
    //if(j%1==0)
       d->drawEllipse(next_point,LED_SIZE,LED_SIZE);
  }
}
}


void Ekran::generuj_Pedzel(QPainter *d)
{


    if(this->isPosChanged)
    {
            d->setBrush(Qt::blue);
            d->setPen(Qt::blue);

            QRect checkRect(this->currentX-CHECK_RECT_SIZE,this->currentY-CHECK_RECT_SIZE,2*CHECK_RECT_SIZE,2*CHECK_RECT_SIZE);


            for(int i=0;i<LED_AMMOUNT;i++)
            {
             for(int j=0;j<360;j++)
             {
        if(checkRect.contains(this->maximumHeight()/2+2*(LED_SIZE*(i+INNER_RING-1)*qCos(j*PI/180))
                ,this->maximumHeight()/2+2*(LED_SIZE*(i-1+INNER_RING)*qSin(j*PI/180))))

            if(this->isClickedLeft) this->tLed[i][j]=true;
             else if(this->isClickedRight) this->tLed[i][j]=false;

             }
            }


}
}



