#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>


#include "classes.h"



class Game
{
public:

	const Point2D m_ScreenDims;
	const Point2D m_Centre;

	Player* m_Player;
	std::vector<Obstructor> m_ObstructorList;

	Game() = delete;
	Game(Point2D screenDims);
	~Game();

	void Init();
	void Run();
	void Close();


};