
#ifndef Wall_CLASS_H
#define Wall_CLASS_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include "Kwadrat.h"
class Wall : public Kwadrat
{

public:
	
	int xx=0;
	int yy=0;
	Wall();
	void Wall_location();
};

#endif