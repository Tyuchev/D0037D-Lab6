#include <iostream>
#include <vector>
#include <string>


#include "classes.h"


// Point2D Struct

Point2D::Point2D(int posX, int posY)
	: x(posX), y(posY)
{
}


// Sprites

Sprite::Sprite()
{
}




//Base Objects

Object::Object(Point2D position)
	: m_Pos(position), m_Sprite(nullptr)
{
}


// Players

Player::Player(Point2D position)
	:Object{position}
{

}

void Player::Move(Point2D moveVector)
{

}


// Obstructors

Obstructor::Obstructor(Point2D position)
	:Object{ position }
{

}

void Obstructor::Move(Point2D moveVector)
{

}