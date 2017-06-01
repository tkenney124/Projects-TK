#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>
#include <ctime>



class Piece
{
public:
    virtual bool canMove(int px, int py, int rx, int ry)=0;
    QImage image;
    bool color;
    void draw(int x, int y, QPainter* paint);
    Piece(bool c);
};

class Rook : public Piece
{
public:
bool canMove(int px, int py, int rx, int ry);
Rook(bool c);
};
class Pawn : public Piece
{
public:
bool canMove(int px, int py, int rx, int ry);
Pawn(bool c);
};
class Knight : public Piece
{
public:
bool canMove(int px, int py, int rx, int ry);
Knight(bool c);
};
class Queen : public Piece
{
public:
bool canMove(int px, int py, int rx, int ry);
Queen(bool c);
};
class Bishop : public Piece
{
public:
bool canMove(int px, int py, int rx, int ry);
Bishop(bool c);
};
class King : public Piece
{
public:
bool canMove(int px, int py, int rx, int ry);
King(bool c);
};
class Chess : public QMainWindow
{
    Q_OBJECT


public:
   int rx;
   int ry;
   int px;
   int py;
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent*);
    Chess(QWidget *parent = 0);
    ~Chess();
};


#endif // CHESS_H
