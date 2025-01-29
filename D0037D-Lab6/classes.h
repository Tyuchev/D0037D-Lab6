#pragma once

#include <iostream>
#include <vector>
#include <string>



struct Point2D
{
	int x, y;

	Point2D() = delete;
	Point2D(int posX, int posY);

};



class Object
{
	Point2D pos;

	Object() = delete;
	Object(Point2D position);

	virtual void Move(Point2D moveVector) = 0;


};


class Player : Object
{

	// override Move(), Constructors

};

class Obstruct : Object
{




};