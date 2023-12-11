#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <player.h>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include "player.h"
#include "food.h"
#include "enemy.h"
#include <QDir>
#include <QDebug>

class bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    int row,column;
    int data[11][11];

public slots:
    void move();
    void keyPressEvent(QKeyEvent* event);
private:

};

#endif // BULLET_H
