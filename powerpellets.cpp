#include "powerpellets.h"

powerPellets::powerPellets() {

    //initializing sprite and value
    sprite.load("C:/Users/Power/Desktop/PacmanGame-master/Assets/powerPellet.png");
    sprite = sprite.scaledToWidth(blockDim);
    sprite = sprite.scaledToHeight(blockDim);
    value = 100;


    //  setpixmap, setPos, addItemToScene will be done in game manager (Fill pellets).
    setPixmap(sprite);
}
