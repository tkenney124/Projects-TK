#include "starrynightwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) //argc count of command line arguments; argv is strings
{
    srand(time(0));
    QApplication a(argc, argv);
    StarryNightWindow w; //constructor for starrynightwindow is called
    w.show();

    return a.exec(); // event loop-dont stop program until window closed
}
