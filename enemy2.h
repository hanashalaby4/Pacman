#ifndef ENEMY2_H
#define ENEMY2_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QRandomGenerator>
class enemy2 : public QObject, public QGraphicsPixmapItem
{
public:
    enemy2(int **boardData);
    int row, column;
public slots:
    void movement();
private:

    int data[31][28];
    int health;
   QTimer *timer;
   QRandomGenerator generator;
private slots:



};


#endif // ENEMY2_H
