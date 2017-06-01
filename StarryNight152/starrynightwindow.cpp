#include "starrynightwindow.h"

StarryNightWindow::StarryNightWindow(QWidget *parent) //initialization here
    : QMainWindow(parent)
{
    // to keep the stars make them here -initializing variables
    for(int i=0;i<20;i++)
    {
         stars[i]=new Star();//range from size 5 to 50
    }
    resize(1000,1000);
    setWindowTitle("Starry Night!!");
}

StarryNightWindow::~StarryNightWindow() // destructor
{

}
void StarryNightWindow::paintEvent(QPaintEvent *event)
{
   // cout << "paint event just happened"<<endl;
    //drawing code
    QPainter* mypainter = new QPainter(this); //takes the window as an object

    for(int i=0;i<20;i++)
    {
        if(stars[i]!=NULL)
            stars[i]->draw(mypainter);

    }
}
void Star::draw(QPainter* mypainter)
{
mypainter->setPen(*c);
mypainter->drawLine(x-s/2,y-s/2,x+s/2,y+s/2);
mypainter->drawLine(x+s/2,y-s/2,x-s/2,y+s/2);
mypainter->drawLine(x-s/2,y,x+s/2,y);
mypainter->drawLine(x,y-s/2,x,y+s/2);
}

Star::Star()
{
    x=rand()%1000;
    y=rand()%1000;
    s=rand()%45+5;
    c=new QColor(rand()%256,rand()%256,rand()%256);
}
void StarryNightWindow::mousePressEvent(QMouseEvent *event)
{
  int x= event->x();
  int y=event->y();
   cout << "You clicked"<<endl;
   for(int i=0;i<20;i++)
   {
       if(stars[i]->WasIClicked(x,y))
       {
           cout<< "I was clicked"<<endl;
           stars[i]=NULL;
           repaint(); //makes paint event happen
       }
   }

}
bool Star::WasIClicked(int mx, int my)
{
    if(mx>=x-s/2 && mx<=x+s/2 && my>=y-s/2 && my<=y+s/2)
        return true;
    return false;
}
