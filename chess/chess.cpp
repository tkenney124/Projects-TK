#include "chess.h"
Piece* board[8][8];


Chess::Chess(QWidget *parent)
    : QMainWindow(parent)
{
resize(44*8,44*8);
for(int y=0;y<8;y++)
{
    for(int x=0;x<8;x++)
    {
        board[x][y]=NULL;
    }
}
board[0][0]=new Rook(false);
board[7][0]=new Rook(false);
board[0][7]=new Rook(true);
board[7][7]=new Rook(true);
board[0][6]=new Pawn(true);
board[1][6]=new Pawn(true);
board[2][6]=new Pawn(true);
board[3][6]=new Pawn(true);
board[4][6]=new Pawn(true);
board[5][6]=new Pawn(true);
board[6][6]=new Pawn(true);
board[7][6]=new Pawn(true);
board[0][1]=new Pawn(false);
board[1][1]=new Pawn(false);
board[2][1]=new Pawn(false);
board[3][1]=new Pawn(false);
board[4][1]=new Pawn(false);
board[5][1]=new Pawn(false);
board[6][1]=new Pawn(false);
board[7][1]=new Pawn(false);
board[1][0]=new Knight(false);
board[6][0]=new Knight(false);
board[1][7]=new Knight(true);
board[6][7]=new Knight(true);
board[5][7]=new Bishop(true);
board[2][7]=new Bishop(true);
board[2][0]=new Bishop(false);
board[5][0]=new Bishop(false);
board[4][0]=new King(false);
board[4][7]=new King(true);
board[3][0]=new Queen(false);
board[3][7]=new Queen(true);


}




Chess::~Chess()
{

}
void Chess::paintEvent(QPaintEvent*)
{
    QPainter paint(this);


    for(int y=0;y<8;y++)
    {
        for(int x=0;x<8;x++)
        {

            if(x %2==0 && y %2==0 || x %2 !=0 && y %2 !=0)
            {
                paint.fillRect(x*44,y*44,44,44,QColor(177,113,24));
            }
            else
            {
                paint.fillRect(x*44,y*44,44,44,QColor(233,174,95));
            }

        }
        for(int y=0;y<8;y++)
        {
            for(int x=0;x<8;x++)
            {
                if(board[x][y]!=NULL)
                {
                    board[x][y]->draw(x,y,&paint);
                }

            }




}
}
}
Piece::Piece(bool c)
{
color=c;
QImage image;

}
Rook::Rook(bool c):Piece(c)
{

    if(c!=false)
    {
        image=QPixmap("wrook.gif").toImage();
    }
    else
    {
        image=QPixmap("brook.gif").toImage();
    }


}
Pawn::Pawn(bool c):Piece(c)
{

    if(c!=false)
    {
        image=QPixmap("wpawn.gif").toImage();
    }
    else
    {
        image=QPixmap("bpawn.gif").toImage();
    }


}
Knight::Knight(bool c):Piece(c)
{

    if(c!=false)
    {
        image=QPixmap("wknight.gif").toImage();
    }
    else
    {
        image=QPixmap("bknight.gif").toImage();
    }


}
Bishop::Bishop(bool c):Piece(c)
{

    if(c!=false)
    {
        image=QPixmap("wbishop.gif").toImage();
    }
    else
    {
        image=QPixmap("bbishop.gif").toImage();
    }


}
King::King(bool c):Piece(c)
{

    if(c!=false)
    {
        image=QPixmap("wking.gif").toImage();
    }
    else
    {
        image=QPixmap("bking.gif").toImage();
    }


}
Queen::Queen(bool c):Piece(c)
{

    if(c!=false)
    {
        image=QPixmap("wqueen.gif").toImage();
    }
    else
    {
        image=QPixmap("bqueen.gif").toImage();
    }


}

void Piece::draw(int x, int y, QPainter* paint)
{
    paint->drawImage(x*44,y*44,image);

}
void Chess::mousePressEvent(QMouseEvent* event)
{

     px=event->x()/44;
     py=event->y()/44;
    qDebug() << px <<" " << py <<endl;


}

void Chess::mouseReleaseEvent(QMouseEvent* event)
{

    rx=event->x()/44;
    ry=event->y()/44;
    qDebug() << rx <<" "<< ry << endl;
    if(board[px][py]!=NULL && board[px][py]!=board[rx][ry])
    {
        if(board[px][py]->canMove(px,py,rx,ry)==true)
        {
            board[rx][ry]=board[px][py];
            board[px][py]=NULL;
             while(true) //try and fix if you have time
             {
                 px=rand() % 8;
                 py=rand() % 8;
                 rx=rand() % 8;
                 ry=rand() % 8;
               if(board[px][py]==NULL) //check if a piece
               {
                   qDebug() << px << " " << py;
                   qDebug() << rx << " " << ry;
                   qDebug() << " got here2";
                   continue;
               }
              else if(board[px][py]!=NULL && board[px][py]!=board[rx][ry]) // it is a piece
               {
                 if(board[px][py]->color==false&& board[px][py]->canMove(px,py,rx,ry)==true) // can it move
               {
                   board[rx][ry]=board[px][py];
                   board[px][py]=NULL;
                   repaint();
                   break;
               }
                 else
                 {
                     continue;
                 }
               }
               else
                   {
                   qDebug() << " got here3";
                       continue;
                   }
         }
            repaint();
        }
        else
        {
            qDebug() << "this is not a valid move" << endl;
            return;

        }
    }

    else
    {
        qDebug()<< "this is not a valid piece" << endl;
        return;


    }



}
/*bool Piece::canMove(int px, int py, int rx, int ry)
{

    return 0;
}*/
bool Pawn::canMove(int px, int py, int rx, int ry)
{
    if(py==6)
    {
    if(board[px][py]->color==true && ry<py && abs(py-ry)<=2 && rx==px)
    {
        if(board[rx][ry] !=NULL && board[rx][ry]->color!=color || board[rx][ry] == NULL)
        {
            return true;
        }
    }
    }
    if(py==1)
    {
    if(board[px][py]->color==false && ry>py && abs(py-ry)<=2 && rx==px)
    {
        if(board[rx][ry] !=NULL && board[rx][ry]->color!=color || board[rx][ry] == NULL)
        {
            return true;
        }
    }
}
    if(board[px][py]->color==true && ry<py && abs(py-ry)==1 && rx==px)
    {
        if(board[rx][ry] !=NULL && board[rx][ry]->color!=color || board[rx][ry] == NULL)
        {
            return true;
        }

    }
   if (board[px][py]->color==false && abs(py-ry)==1 && ry>py && rx==px)
        {
            if(board[rx][ry] !=NULL && board[rx][ry]->color!=color || board[rx][ry] == NULL)
            {
                return true;
            }
        }



return false;
}



bool Queen::canMove(int px, int py, int rx, int ry)
{
    if(abs(py-ry)==abs(px-rx)&& px < rx && py < ry)
         //going  diagonal in positive x/y direction
        {int i=1;
           while(true)
           {

           qDebug() << "loop iteration" << i << endl;

           if(board[px+i][py+i]!=NULL&& px+i!=rx && py+i!=ry)
           {

               return false;

           }
           else if((py+i==ry && px+i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px+i==rx && py+i==ry && board[rx][ry] == NULL) )
           {
               return true;


           }
           else
           {
                i=i+1;
               continue;
           }

        }
        }
    if(abs(py-ry)==abs(px-rx)&& px > rx && py < ry)
         //going  diagonal in negative x/pos y direction
        {int i=1;
           while(true)
           {

           qDebug() << "loop iteration" << i << endl;

           if(board[px-i][py+i]!=NULL && px-i!=rx && py+i!=ry)
           {

               return false;

           }
           else if((py+i==ry && px-i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px-i==rx && py+i==ry && board[rx][ry] == NULL) )
           {
                return true;

           }
           else
           {
                i=i+1;
               continue;
           }

        }
        }
    if(abs(py-ry)==abs(px-rx)&& px < rx && py > ry)
         //going  diagonal in pos x/neg y direction
        {int i=1;
           while(true)
           {

           qDebug() << "loop iteration" << i << endl;

           if(board[px+i][py-i]!=NULL && px+i!=rx && py-i!=ry)
           {

               return false;

           }
           else if((py-i==ry && px+i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px+i==rx && py-i==ry && board[rx][ry] == NULL) )
           {
                return true;

           }
           else
           {
                i=i+1;
               continue;
           }

        }
        }
    if(abs(py-ry)==abs(px-rx)&& px > rx && py > ry)
         //going  diagonal in negative x/neg y direction
        {int i=1;
           while(true)
           {

           qDebug() << "loop iteration" << i << endl;

           if(board[px-i][py-i]!=NULL && px-i!=rx && py-i!=ry)
           {

               return false;

           }
           else if((py-i==ry && px-i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px-i==rx && py-i==ry && board[rx][ry] == NULL) )
           {
                return true;

           }
           else
           {
                i=i+1;
               continue;
           }

        }
        }

    if(px==rx && py < ry) //going  down
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[px][py+i]!=NULL && py+i!=ry)
       {

           return false;

       }
       else if((py+i==ry && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(py+i==ry && board[rx][ry] == NULL) )
       {
           return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    if(px==rx && ry < py) //going  up
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[px][ry+i]!=NULL && ry+i!=py)
       {

           return false;

       }
       else if((ry+i==py && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(ry+i==py && board[rx][ry] == NULL) )
       {
            return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    if(py==ry && px > rx) //going  left
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[rx+i][py]!=NULL && rx+i!=px)
       {

           return false;

       }
       else if((rx+i==px && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(rx+i==px && board[rx][ry] == NULL) )
       {
            return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    if(py==ry && rx > px) //going  right
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[px+i][py]!=NULL && px+i!=rx)
       {

           return false;

       }
       else if((px+i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px+i==rx && board[rx][ry] == NULL) )
       {
           return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
       else
       {
           return false;
       }
    return false;
    }





bool King::canMove(int px, int py, int rx, int ry)
{
    if(abs(px-rx)<=1 && abs(py-ry)<=1 && (abs(px-rx)<=1 && abs(py-ry)<=1))
    {
       if(board[rx][ry] !=NULL && board[rx][ry]->color!=color || board[rx][ry] == NULL)
       {
           return true;
       }
    }


    return 0;

}
bool Bishop::canMove(int px, int py, int rx, int ry)
{

   if(abs(py-ry)==abs(px-rx)&& px < rx && py < ry)
        //going  diagonal in positive x/y direction
       {int i=1;
          while(true)
          {

          qDebug() << "loop iteration" << i << endl;

          if(board[px+i][py+i]!=NULL&& px+i!=rx && py+i!=ry)
          {

              return false;

          }
          else if((py+i==ry && px+i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px+i==rx && py+i==ry && board[rx][ry] == NULL) )
          {
              return true;


          }
          else
          {
               i=i+1;
              continue;
          }

       }
       }
   if(abs(py-ry)==abs(px-rx)&& px > rx && py < ry)
        //going  diagonal in negative x/pos y direction
       {int i=1;
          while(true)
          {

          qDebug() << "loop iteration" << i << endl;

          if(board[px-i][py+i]!=NULL && px-i!=rx && py+i!=ry)
          {

              return false;

          }
          else if((py+i==ry && px-i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px-i==rx && py+i==ry && board[rx][ry] == NULL) )
          {
               return true;

          }
          else
          {
               i=i+1;
              continue;
          }

       }
       }
   if(abs(py-ry)==abs(px-rx)&& px < rx && py > ry)
        //going  diagonal in pos x/neg y direction
       {int i=1;
          while(true)
          {

          qDebug() << "loop iteration" << i << endl;

          if(board[px+i][py-i]!=NULL && px+i!=rx && py-i!=ry)
          {

              return false;

          }
          else if((py-i==ry && px+i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px+i==rx && py-i==ry && board[rx][ry] == NULL) )
          {
               return true;

          }
          else
          {
               i=i+1;
              continue;
          }

       }
       }
   if(abs(py-ry)==abs(px-rx)&& px > rx && py > ry)
        //going  diagonal in negative x/neg y direction
       {int i=1;
          while(true)
          {

          qDebug() << "loop iteration" << i << endl;

          if(board[px-i][py-i]!=NULL && px-i!=rx && py-i!=ry)
          {

              return false;

          }
          else if((py-i==ry && px-i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px-i==rx && py-i==ry && board[rx][ry] == NULL) )
          {
               return true;

          }
          else
          {
               i=i+1;
              continue;
          }

       }
       }



    return false;
}
bool Knight::canMove(int px, int py, int rx, int ry)
{
    if((abs(rx-px)==1 && abs(ry-py)==2) || (abs(rx-px)==2 && abs(ry-py)==1))
    {

    if(board[rx][ry] !=NULL && board[rx][ry]->color!=color || board[rx][ry] == NULL)
    {
        return true;
    }

    }
    return 0;
}
bool Rook::canMove(int px, int py, int rx, int ry)
{

    if(px==rx && py < ry) //going  down
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[px][py+i]!=NULL && py+i!=ry)
       {

           return false;

       }
       else if((py+i==ry && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(py+i==ry && board[rx][ry] == NULL) )
       {
           return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    if(px==rx && ry < py) //going  up
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[px][ry+i]!=NULL && ry+i!=py)
       {

           return false;

       }
       else if((ry+i==py && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(ry+i==py && board[rx][ry] == NULL) )
       {
            return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    if(py==ry && px > rx) //going  left
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[rx+i][py]!=NULL && rx+i!=px)
       {

           return false;

       }
       else if((rx+i==px && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(rx+i==px && board[rx][ry] == NULL) )
       {
            return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    if(py==ry && rx > px) //going  right
    {int i=1;
       while(true)
       {

       qDebug() << "loop iteration" << i << endl;

       if(board[px+i][py]!=NULL && px+i!=rx)
       {

           return false;

       }
       else if((px+i==rx && board[rx][ry] !=NULL && board[rx][ry]->color!=color) ||(px+i==rx && board[rx][ry] == NULL) )
       {
           return true;

       }
       else
       {
            i=i+1;
           continue;
       }

    }
    }
    return false;
}













