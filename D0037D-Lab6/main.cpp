#include <iostream>
#include <vector>
#include <string>

#include "classes.h"
#include "game.h"



int main()
{
	std::cout << "Hello World" << std::endl;

	//  1920 x 1080 
	Game game{ Point2D{1920, 1080} };

	game.Init();

	game.Run();

	game.Close();

	return 0;
}
