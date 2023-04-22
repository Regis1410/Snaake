#ifndef Kwadrat_CLASS_H
#define Kwadrat_CLASS_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <vector>
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


class Kwadrat
{
public:
	
	int vertNum;
	int indicNum ;
	int sizevertices;
	int sizeindices;
	GLfloat* vertices;
	GLuint* indices;

	GLfloat x;
	GLfloat y;

	int Number_additional_squares;


	Kwadrat();
	void Growsnake();
	void Movement(const int& Direction_Movement);
	void reset_snake();
	void X_y_addon_snake();
	



};
#endif
