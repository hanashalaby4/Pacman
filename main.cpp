#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "food.h"
#include "heart.h"
#include <QDir>
#include <QDebug>
#include <QGraphicsTextItem>

//extern enemy enemy3();
//extern heart h[3];
extern Food f;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene *scene = nullptr;

    //qDebug() << "here"; // You can use this for tracing

    view.setFixedSize(650, 650);
    view.setWindowTitle("Maze Game");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);

    //QGraphicsScene *gameScene; //this is the main game scene of our view, we can add multiple scenes if we want later
    int** boardData; //array to save the board.txt
    int blockDim = 20; //the length and width of each row and column in pixels (dimensions of each row and col in pixels)
    int margin = 30; //margin from the board to the view borders, it will be the same from all sides for simplicity
    int sceneDim = 31*blockDim + 2*margin; //this is the dimension of the scene, the length and width of the scene, it will be a square for simplicity
    QGraphicsPixmapItem **boardImages; //this will save the images of the board
     scene=new QGraphicsScene;
       view.QGraphicsView::setFixedSize(sceneDim, sceneDim);
      boardData=new int*[31];
      for(int i=0;i<31;i++){
          boardData[i]=new int[28];
      }
      QFile file("C:/Users/Power/Desktop/Project/Board.txt");
      file.open(QIODevice::ReadOnly);
      QString temp;
      QTextStream stream(&file);
      for(int i=0; i<31; i++){
          for(int j=0; j<28; j++){
              stream >> temp;
              boardData[i][j] = temp.toInt();
          }
      }

       player pacman(boardData);

      QPixmap edgeImageH("C:/Users/Power/Desktop/PacmanGame-master/Assets/edgeH.png");
      edgeImageH = edgeImageH.scaledToWidth(blockDim);
      edgeImageH = edgeImageH.scaledToHeight(blockDim);
      QPixmap edgeImageV("C:/Users/Power/Desktop/PacmanGame-master/Assets/edgeV.png");
      edgeImageV = edgeImageV.scaledToWidth(blockDim);
      edgeImageV = edgeImageV.scaledToHeight(blockDim);
      QPixmap cornerImageTL("C:/Users/Power/Desktop/PacmanGame-master/Assets/cornerTL.png");
      cornerImageTL = cornerImageTL.scaledToWidth(blockDim);
      cornerImageTL = cornerImageTL.scaledToHeight(blockDim);
      QPixmap cornerImageTR("C:/Users/Power/Desktop/PacmanGame-master/Assets/cornerTR.png");
      cornerImageTR = cornerImageTR.scaledToWidth(blockDim);
      cornerImageTR = cornerImageTR.scaledToHeight(blockDim);
      QPixmap cornerImageBR("C:/Users/Power/Desktop/PacmanGame-master/Assets/cornerBR.png");
      cornerImageBR = cornerImageBR.scaledToWidth(blockDim);
      cornerImageBR = cornerImageBR.scaledToHeight(blockDim);
      QPixmap cornerImageBL("C:/Users/Power/Desktop/PacmanGame-master/Assets/cornerBL.png");
      cornerImageBL = cornerImageBL.scaledToWidth(blockDim);
      cornerImageBL = cornerImageBL.scaledToHeight(blockDim);

      boardImages = new QGraphicsPixmapItem*[31];
      for(int i=0; i<31; i++){
          boardImages[i] = new QGraphicsPixmapItem[28];
      }

      for (int i=0; i<31;i++){
          for(int j=0;j<28;j++){

              if(boardData[i][j] == -1){
                  //vertical edge image
                  boardImages[i][j].setPixmap(edgeImageV);
              }else if (boardData[i][j] == -2){
                  //horizontal edge image
                  boardImages[i][j].setPixmap(edgeImageH);
              }else if(boardData[i][j] == -3){
                  boardImages[i][j].setPixmap(cornerImageTL);
              }else if(boardData[i][j] == -4){
                  boardImages[i][j].setPixmap(cornerImageTR);
              }else if(boardData[i][j] == -5){
                  boardImages[i][j].setPixmap(cornerImageBR);
              }else if(boardData[i][j] == -6){
                  boardImages[i][j].setPixmap(cornerImageBL);
              }

              //positioning the images using simple relations.
              boardImages[i][j].setPos(blockDim*j + margin, blockDim*i + margin);

              //we must render our items, add the images to the scene
              scene->addItem(&boardImages[i][j]);
          }
      }


    /*QFile file("C:/Users/Power/Desktop/Project/Board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int boardData[11][11];
    QString temp;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap grassImage("C:/Users/Power/Desktop/Project/Grass.png");
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);

    QPixmap bricksImage("C:/Users/Power/Desktop/PacmanGame-master/Assets/edgeH.png");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);

    QPixmap HouseImage("C:/Users/Power/Desktop/Project/house.jpeg");
    HouseImage = HouseImage.scaledToWidth(50);
    HouseImage = HouseImage.scaledToHeight(50);*/



   /* QGraphicsPixmapItem boardItems[11][11];
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {
            // Set Image
            if (boardData[i][j] < 0)
                boardItems[i][j].setPixmap(bricksImage);
            else
            boardItems[i][j].setPixmap(grassImage);

            // Set Position
            boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene.addItem(&boardItems[i][j]);
        }*/

    /*player player(boardData);
    scene->addItem(&player);
    player.h[0].setPos(500,75);
    scene->addItem(&player.h[0]);
    player.h2[0].setPos(525,75);
    player.h3[0].setPos(550,75);
    scene->addItem(&player.h2[0]);
    scene->addItem(&player.h3[0]);*/

    Food food,food2;
    food.setPos(100, 250);
    food2.setPos(250, 100);
    scene->addItem(&food);
    scene->addItem(&food2);


  /*  bullet bullet,bullet2,bullet3,bullet4;
    bullet.setPos(110, 110);    //setPos(50 + Column() * 50, 50 + (1+p.getRow()) * 50);
    bullet2.setPos(500,500);
    bullet3.setPos(500,110);
    bullet4.setPos(110,500);

    scene->addItem(&bullet);
    scene->addItem(&bullet2);
    scene->addItem(&bullet3);
    scene->addItem(&bullet4);
    bullet.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    bullet.setFocus();

    enemy enemy(boardData);

    //enemy.setPos(50 + 9 * 50, 50 + 9 * 50);
    scene->addItem(&enemy);

    enemy2 enemyy(boardData);

    //enemyy.setPos(50 + 2 * 50, 50 + 9 * 50);
    scene->addItem(&enemyy);*/


    heart h[3];
    h[0].setPos(500,75);



    pacman.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    pacman.setFocus();

    view.setScene(scene);
    view.show();


    return a.exec();


}
