#include "enemy.h"
#include "player.h"
#include <QTimer>
#include <qglobal.h>
#include <QRandomGenerator>
#include "QtCore/qobjectdefs.h"
extern Player p;

enemy::enemy(int **boardData)
{

    // Set Image
    QPixmap image("C:/Users/Power/Desktop/Project/ene.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 9;
    column = 8;
    setPos(50 + column * 50, 50 + row * 50);
    health=2;


    // Set data Array
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 28; j++)
            data[i][j] = boardData[i][j];

    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&enemy::movement);
    timer->start(250);

}
void enemy::movement()
{

    int x;
    x=generator.bounded(1, 5);
//    qDebug()<<x;
    if (x != 2 && x !=3 && x != 4 && data[row - 1][column] >= 0)
    {
    row--;
    setPos(50 + column * 50, 50 + row * 50);
    }
       if (x != 1 && x !=3 && x != 4 && data[row + 1][column] >= 0)
        {
           row ++;
           setPos(50 + column * 50, 50 + row * 50);
        }

           if (x != 1 && x !=2 && x != 4 && data[row][column + 1] >= 0)
           {
               column++;
               setPos(50 + column * 50, 50 + row * 50);

           }
           if (x != 1 && x != 2 && x != 3 && data[row][column - 1] >= 0)
           {
               column--;
               setPos(50 + column * 50, 50 + row * 50);
           }

}

