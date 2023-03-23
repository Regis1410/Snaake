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
};

#endif

