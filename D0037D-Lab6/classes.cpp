#include <iostream>
#include <vector>
#include <string>


#include "classes.h"


// Point2D Struct

Point2D::Point2D(float posX, float posY)
	: x(posX), y(posY)
{
}


// Sprites

Sprite::Sprite()
{
}



//Base Objects

Object::Object(Point2D position)
	: m_Pos(position), m_Velocity(Point2D(0, 0)), m_Sprite(nullptr)
{
}

Object::Object(Point2D position, Point2D velocity)
	: m_Pos(position), m_Velocity(velocity), m_Sprite(nullptr)
{
}


// Players

Player::Player(Point2D position)
	:Object{position}
{
}

Player::Player(Point2D position, Point2D velocity)
	: Object{ position, velocity }
{
}

void Player::Move()
{
	m_Pos = m_Pos + m_Velocity;
}

void Player::Update()
{
	GetInput();
	Move();
}

void Player::GetInput()
{
	//SDL_Event event;

	//while (SDL_PollEvent(&event)) {
	//	if (event.type == SDL_KEYDOWN) 
	//	{
	//		if (event.key.keysym.sym == SDLK_W)
	//		{
	//			// Add forward velocity - IF NOT OVER MAX
	//		}
	//		// else if (event.key.keysym.sym == SDLK_S)
	//		// Do I want "braking" to be a thing? Reversing?
	//		
	//		if (event.key.keysym.sym == SDLK_A)
	//		{
	//			// Rotate Anti-clockwise
	//		}
	//		if (event.key.keysym.sym == SDLK_D)
	//		{
	//			// Rotate Clockwise
	//		}
	//	}
	//	else
	//	{
	//		continue;
	//	}
	// 
	//}
}


// Obstructors

Obstructor::Obstructor(Point2D position)
	:Object{position}
{
}

Obstructor::Obstructor(Point2D position, Point2D velocity)
	: Object{ position, velocity }
{
}

void Obstructor::Move()
{
	m_Pos = m_Pos + m_Velocity;
}

void Obstructor::Update()
{
	Move();
}