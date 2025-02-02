#pragma once

#include <iostream>
#include <vector>
#include <string>



struct Point2D
{
	int x, y;

	Point2D() = delete;
	Point2D(int posX, int posY);

	Point2D operator / (int div) const
	{
		Point2D result{0,0};
		result.x = x / div;
		result.y = y / div;
		return result;
	}

	Point2D operator + (Point2D& rhs) const
	{
		Point2D result{x + rhs.x, y + rhs.y};

		return result;
	}

};


class Sprite
{
public:

	Sprite();

};


class Object
{
public:

	Point2D m_Pos;
	Sprite* m_Sprite;
	

	Object() = delete;
	Object(Point2D position);

	virtual void Move(Point2D moveVector) = 0;


};


class Player : Object
{
public:

	Player() = delete;
	Player(Point2D position);

	virtual void Move(Point2D moveVector) override;


};

class Obstructor : Object
{
public:

	Obstructor() = delete;
	Obstructor(Point2D position);

	virtual void Move(Point2D moveVector) override;


};