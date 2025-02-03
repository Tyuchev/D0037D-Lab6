#pragma once

#include <iostream>
#include <vector>
#include <string>



struct Point2D
{
	float x, y;

	Point2D() = delete;
	Point2D(float posX, float posY);


	bool operator == (Point2D& rhs) const
	{
		return x == rhs.x ? y == rhs.y ? true : false : false;
	}

	Point2D operator + (Point2D& rhs) const
	{
		Point2D result{ x + rhs.x, y + rhs.y };

		return result;
	}

	Point2D operator * (float div) const
	{
		Point2D result{ 0,0 };
		result.x = x * div;
		result.y = y * div;
		return result;
	}

	Point2D operator / (float div) const
	{
		Point2D result{0,0};
		result.x = x / div;
		result.y = y / div;
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
	Point2D m_Velocity;
	Sprite* m_Sprite;
	

	Object() = delete;
	Object(Point2D position);
	Object(Point2D position, Point2D velocity);

	virtual void Move() = 0;
	virtual void Update() = 0;

};


class Player : public Object
{
public:

	Player() = delete;
	Player(Point2D position);
	Player(Point2D position, Point2D velocity);

	virtual void Move() override;
	virtual void Update() override;

	void GetInput();
};

class Obstructor : public Object
{
public:

	Obstructor() = delete;
	Obstructor(Point2D position);
	Obstructor(Point2D position, Point2D velocity);

	virtual void Move() override;
	virtual void Update() override;
};