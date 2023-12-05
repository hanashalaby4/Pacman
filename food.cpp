#include "food.h"

Food::Food()
{
    // Set Image
    QPixmap image("C:/Users/Power/Desktop/Project/gunnn.png");
    image = image.scaledToWidth(30);
    image = image.scaledToHeight(30);
    setPixmap(image);

    // Set Position
    //setPos(50 + 5 * 50, 50 + 5 * 50);
}
