#include "enemy2.h"
enemy2::enemy2(int** boardData)
{

    // Set Image
    QPixmap image("C:/Users/Power/Desktop/Project/trevor.png");
    image = image.scaledToWidth(70);
    image = image.scaledToHeight(70);
    setPixmap(image);

    // Set Position
    row = 9;
    column = 2;
    setPos(50 + column * 50, 50 + row * 50);
    health=2;


    // Set data Array
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 28; j++)
            data[i][j] = boardData[i][j];

    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&enemy2::movement);
    timer->start(250);

}
void enemy2::movement()
{

    int x;
    x=generator.bounded(1, 5);

    if (x != 1 && x !=3 && x != 4 && data[row - 1][column] >= 0)
    {
    row--;
    setPos(50 + column * 50, 50 + row * 50);
    }
    else if (x != 2 && x !=3 && x != 4 && data[row + 1][column] >= 0)
    {
           row ++;
           setPos(50 + column * 50, 50 + row * 50);
    }
    else if (x != 1 && x !=2 && x != 3 && data[row][column + 1] >= 0)
           {
               column++;
               setPos(50 + column * 50, 50 + row * 50);

           }
    else if (x != 1 && x != 2 && x != 4 && data[row][column - 1] >= 0)
           {
               column--;
               setPos(50 + column * 50, 50 + row * 50);
           }

}

