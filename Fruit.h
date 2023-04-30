#ifndef Fruit_CLASS_H
#define Fruit_CLASS_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include "Kwadrat.h"
class Fruit : public Kwadrat
{
public:



	Fruit();
	void Fruit_location();	
	int random_x;
	int random_y;

private:

	int previous_x = 0;
	int previous_y = 0;
	void Random_xy();
	void check_xy();
	GLfloat gfloat_random_x;
	GLfloat gLfloat_random_y;
};

#endif

