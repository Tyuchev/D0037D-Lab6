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
	bool m_ShouldRunFlag;

	Player* m_Player;
	std::vector<Obstructor> m_ObstructorList;

	Game() = delete;
	Game(Point2D screenDims);
	~Game();

	void Init();
	void Run();
	void Close();

	void UpdateAll();
	void CollisionChecks();
	void EdgeCheck();

	void HandlePlayerInput();

	Point2D Normalise(Point2D point);

};