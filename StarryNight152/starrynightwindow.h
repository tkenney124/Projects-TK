#ifndef STARRYNIGHTWINDOW_H
#define STARRYNIGHTWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QPainter>
#include <ctime>
#include <Qcolor>
#include <QMouseEvent>
using namespace std;

class Star
{
private:
    int x,y,s;
    QColor* c;
public:
    bool WasIClicked(int mx, int my);
    void draw(QPainter*);
    Star(); //sets x, y , s
};

class StarryNightWindow : public QMainWindow
{
    Q_OBJECT

public:
    StarryNightWindow(QWidget *parent = 0);
    ~StarryNightWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //storing the stars
    Star* stars[100];

};


#endif // STARRYNIGHTWINDOW_H
