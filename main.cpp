#include "gamemanager.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


//extern enemy enemy3();
//extern heart h[3];
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameManager gameManager;
    gameManager.QGraphicsView::show();



    return a.exec();


}
