#include <iostream>
#include <vector>
#include <string>


#include "classes.h"




Point2D::Point2D(int posX, int posY)
	: x(posX), y(posY)
{
}





Object::Object(Point2D position)
	: pos(position)
{
}


//  1920 x 1080