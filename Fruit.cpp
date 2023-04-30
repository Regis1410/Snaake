#include "Fruit.h"
#include <cstring>
#include <stdlib.h>

void Fruit::Random_xy()
{
	srand(time(0));
	//random x 
	random_x = (rand() % 183) - 100;



	if (random_x % 10 != 0)
	{
		random_x = random_x - (random_x % 10);
	}

	
	this->gfloat_random_x = ((GLfloat)random_x / 100) - 0.02;


	//random y
	random_y = (rand() % 183) - 100;

	if (random_y % 10 != 0)
	{
		random_y = random_y - (random_y % 10);
	}


	this->gLfloat_random_y = ((GLfloat)random_y / 100) + 0.02;
	//if fruit gets old fruit location 


	
}




void Fruit::check_xy()
{
	while (random_x == this->previous_x && random_y == this->previous_y)
	{

		random_x = (rand() % 183) - 100;

		if (random_x % 10 != 0)
		{
			random_x = random_x - (random_x % 10);
		}

		this->gfloat_random_x = ((GLfloat)random_x / 100) - 0.02;


		//random y
		random_y = (rand() % 183) - 100;

		if (random_y % 10 != 0)
		{
			random_y = random_y - (random_y % 10);
		}
		this->gLfloat_random_y = ((GLfloat)random_y / 100) + 0.02;


	}

	this->previous_y = random_y;
	this->previous_x = random_x;

	x = random_x;
	y = random_y;





}







void Fruit::Fruit_location()
{
	Random_xy();
	check_xy();

	// upper left corner
	this->vertices[0] = this->gfloat_random_x;
	this->vertices[1] = this->gLfloat_random_y;
	// upper right corner
	this->vertices[3] = this->gfloat_random_x + 0.04;
	this->vertices[4] = this->gLfloat_random_y;
	// lower left corner
	this->vertices[6] = this->gfloat_random_x;;
	this->vertices[7] = this->gLfloat_random_y - 0.04;
	// lower rigth corner
	this->vertices[9] = gfloat_random_x + 0.04;
	this->vertices[10] = this->gLfloat_random_y - 0.04;

	
	


}

Fruit::Fruit()
{

	Fruit::Fruit_location();


}