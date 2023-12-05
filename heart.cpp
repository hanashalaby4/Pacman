#include "heart.h"

heart::heart()
{
    QPixmap image("C:/Users/Power/Desktop/Project/heart.png");
    image = image.scaledToWidth(20);
    image = image.scaledToHeight(20);
    setPixmap(image);

}

