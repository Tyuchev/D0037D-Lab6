#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "game.h"
#include "classes.h"


//  1920 x 1080


Game::Game(Point2D screenDims)
	: m_ScreenDims(screenDims), m_Centre(screenDims / 2), m_ShouldRunFlag(true)
{
}

Game::~Game()
{

}


void Game::Init()
{
	// Create Player

	m_Player = new Player(m_Centre);

	// Create Obstructors
	// 
	// 5 Far Asteroids

	for (int i = 0; i < 5; i++)
	{
		// Work out asteroid positions
		// They would start to overlap if I had more than 10 asteroids created this way
		
		// Use i to generate an even range of asteroid positions
		float clampI = (i % 10) * 0.1f;
		float iSegment = clampI * 360;

		float sinX = sin(iSegment);
		float sinY = cos(iSegment);

		float relativeX = m_Centre.x * sinX;
		float relativeY = m_Centre.y * sinY;
		Point2D relativePos{relativeX, relativeY};

		// Start the asteroids moving towards the centre of the window (Player spawn)
		Point2D velocity = Normalise(relativePos * -1); 

		Point2D position = m_Centre + relativePos;
		Obstructor asteroid{position, velocity};

		m_ObstructorList.push_back(asteroid);
	}

	// 5 Near asteroids

	for (int i = 0; i < 5; i++)
	{
		// Work out asteroid positions
		// They would start to overlap if I had more than 10 asteroids created this way

		// Use i to generate an even range of asteroid positions

		float offset = 0.5f; // To create a slight difference between the inner and outer asteroid positioning
		float clampI = ((i % 10) + offset) * 0.1f;
		float iSegment = clampI * 360;

		float sinX = sin(iSegment);
		float sinY = cos(iSegment);

		float relativeX = m_Centre.x / 2.0f * sinX;
		float relativeY = m_Centre.y / 2.0f * sinY;
		Point2D relativePos{ relativeX, relativeY };

		// Start the asteroids moving towards the centre of the window (Player spawn)
		Point2D velocity = Normalise(relativePos * -1);

		Point2D position = m_Centre + relativePos;
		Obstructor asteroid{ position };

		m_ObstructorList.push_back(asteroid);
	}
}

void Game::Run()
{
	while (m_ShouldRunFlag)
	{
		UpdateAll();
		CollisionChecks();

		if (true)
		{
			// Implement collation of frames
			HandlePlayerInput();
		}
		
	}
	
}

void Game::Close()
{
	// Occurs when m_ShouldRunFlag is set to false
}

void Game::UpdateAll()
{
	for (auto& const obstructor : m_ObstructorList)
	{
		obstructor.Update();
	}
}

void Game::HandlePlayerInput()
{
	m_Player->GetInput();
}

void Game::CollisionChecks()
{
	Point2D playerPos = m_Player->m_Pos;

	for (auto& const obstructor : m_ObstructorList)
	{
		Point2D obstructPos = obstructor.m_Pos;
		if (playerPos == obstructPos)
		{
			// Resolve collision
			m_ShouldRunFlag = false;
			return;
		}

	}

	EdgeCheck();

}

void Game::EdgeCheck()
{
	std::vector<Object*> objectList;
		
	for (auto& const object : m_ObstructorList)
	{
		objectList.push_back(&object);
	}
	objectList.push_back(m_Player);


	for (auto& const object : objectList)
	{
		Point2D objectPos = object->m_Pos;

		if (objectPos.x > m_ScreenDims.x)
		{
			object->m_Pos.x = 0;

		}
		else if (objectPos.x < 0)
		{
			object->m_Pos.x = m_Centre.x * 2;
		}

		if (objectPos.y > m_ScreenDims.y)
		{
			object->m_Pos.y = 0;

		}
		else if (objectPos.y < 0)
		{
			object->m_Pos.y = m_Centre.y * 2;
		}

	}
}

Point2D Game::Normalise(Point2D point)
{
	float length = sqrt(point.x * point.x + point.y * point.y);

	Point2D result{ point.x / length, point.y / length };

	return result;
}