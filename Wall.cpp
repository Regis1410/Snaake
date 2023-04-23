#include "Wall.h"
#include <cstring>
#include <stdlib.h>



void Wall::Wall_location(const Fruit& Fruit)
{

	srand(time(0));
	//random x 
	int random_x = (rand() % 183) - 100;
	double double_random_x;
	double double_random_y;

	if (random_x % 10 != 0)
	{
		random_x = random_x - (random_x % 10);
		
	}


	double_random_x = ((double)random_x / 100);


	//random y
	int random_y = (rand() % 183) - 100;

	if (random_y % 10 != 0)
	{
		random_y = random_y - (random_y % 10);
		
	}


	double_random_y = ((double)random_y / 100);


	
	
	
	while (random_y == Fruit.random_y && random_x == Fruit.random_x)
	{
		
		random_x = (rand() % 183) - 100;



		if (random_x % 10 != 0)
		{
			random_x = random_x - (random_x % 10);
		}

		double_random_x = ((double)random_x / 100);
		

		//random y
	    random_y = (rand() % 183) - 100;

		if (random_y % 10 != 0)
		{
			random_y = random_y - (random_y % 10);
		}

		double_random_y = ((double)random_y /  100);

		





	}

	std::cout << double_random_x << std::endl;
	
std::cout << double_random_y << std::endl;
double_random_x -= 0.05f;
double_random_y += 0.05f;
	// upper left corner
	this->vertices[0] = double_random_x;
	this->vertices[1] = double_random_y;
	// upper right corner
	this->vertices[3] = double_random_x + 0.10f;
	this->vertices[4] = double_random_y;
	// lower left corner
	this->vertices[6] = double_random_x;
	this->vertices[7] = double_random_y - 0.10f;
	// lower rigth corner
	this->vertices[9] = double_random_x + 0.10f;
	this->vertices[10] = double_random_y - 0.10f;


	//std::cout << double_random_x << " " << double_random_y;	// upper right corner << std::endl
		      

}





Wall::Wall(const Fruit& Fruit) {

	

	Wall_location(Fruit);

}