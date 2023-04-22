#include "Fruit.h"
#include <cstring>
#include <stdlib.h>
void Fruit::Fruit_location()
{
	srand(time(0));
	//random x 
	int random_x = (rand() % 183) - 100;

	

	if (random_x % 10 != 0)
	{
		random_x = random_x - (random_x % 10);
	}

	GLfloat double_random_x;
	double_random_x = ((double)random_x / 100) - 0.02;


	//random y
	int random_y = (rand() % 183) - 100;

	if (random_y % 10 != 0)
	{
		random_y = random_y - (random_y % 10);
	}

	GLfloat double_random_y;
	double_random_y = ((double)random_y / 100) + 0.02;


	

	//if fruit gets old fruit location 
	while (random_x == this->xx && random_y == this->yy)
	{

		 random_x = (rand() % 183) - 100;

		if (random_x % 10 != 0)
		{
			random_x = random_x - (random_x % 10);
		}

		double_random_x = ((double)random_x / 100) - 0.02;


		//random y
		 random_y = (rand() % 183) - 100;

		if (random_y % 10 != 0)
		{
			random_y = random_y - (random_y % 10);
		}
		double_random_y = ((double)random_y / 100) + 0.02;
		std::cout << "test";

	}

	this->yy = random_y;
	this->xx = random_x;

	x = random_x;
	y = random_y;
	//making fruit small

	// upper left corner
	this->vertices[0] = double_random_x;
	this->vertices[1] = double_random_y;
	// upper right corner
	this->vertices[3] = double_random_x + 0.04;
	this->vertices[4] = double_random_y;
	// lower left corner
	this->vertices[6] = double_random_x;;
	this->vertices[7] = double_random_y - 0.04;
	// lower rigth corner
	this->vertices[9] = double_random_x + 0.04;
	this->vertices[10] = double_random_y - 0.04;

	
	


}

Fruit::Fruit()
{

	Fruit::Fruit_location();


}