#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QRandomGenerator>
class enemy : public QObject, public QGraphicsPixmapItem
{
public:
    enemy(int **boardData);
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

#endif // ENEMY_H
