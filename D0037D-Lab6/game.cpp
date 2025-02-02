#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "game.h"
#include "classes.h"


//  1920 x 1080


Game::Game(Point2D screenDims)
	: m_ScreenDims(screenDims), m_Centre(screenDims / 2)
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
	// Far Asteroids

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
		Point2D relativePos{int(relativeX), int(relativeY)};

		Point2D position = m_Centre + relativePos;
		Obstructor asteroid{position};

		m_ObstructorList.push_back(asteroid);
	}

	// Near asteroids

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

		float relativeX = (float(m_Centre.x) / 2.0f) * sinX;
		float relativeY = (float(m_Centre.y) / 2.0f) * sinY;
		Point2D relativePos{ int(relativeX), int(relativeY) };

		Point2D position = m_Centre + relativePos;
		Obstructor asteroid{ position };

		m_ObstructorList.push_back(asteroid);
	}
}

void Game::Run()
{

}

void Game::Close()
{

}