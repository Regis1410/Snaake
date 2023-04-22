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


	int xx=0;
	int yy = 0;
	Fruit();
	void Fruit_location();
	int x_fruit;
	int y_fruit;
};

#endif

