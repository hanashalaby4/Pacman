#include "bullet.h"
#include <QDebug>

bullet::bullet()
{
    row = 1;
    column = 1;
    // Set Image
    QPixmap image("C:/Users/Power/Desktop/Project/ballo.png");
    image = image.scaledToWidth(60);
    image = image.scaledToHeight(50);
    setPixmap(image);
//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
//    timer->start(50);

}
void bullet::move()
{



}

void bullet::keyPressEvent(QKeyEvent *event)
{

    //setPos(50 + p.getColumn() * 50, 50 + (1+p.getRow()) * 50);

//    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
//    {
//        row--;
//        qDebug() << "hereeeeeeee";
//    }
//    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
//    {
//        row++;
//        qDebug() << "hereeeeeeee";
//    }
//    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
//    {
//        column++;
//        qDebug() << "hereeeeeeee";
//    }
//    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
//    {
//        column--;
//        qDebug() << "hereeeeeeee";
//    }

}
