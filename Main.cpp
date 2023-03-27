#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Kwadrat.h"
#include<conio.h>
#include "Fruit.h"
#include <iomanip>
Fruit f1;
Kwadrat K1;
int register_to_grow=0;
int register_to_move;
int Direction_Movement;
int dont_go_back;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

VAO addbricktosnake(VAO VAO1, VAO VAO3);

VAO MoveSnake(VAO VAO1);

VAO Game_over_wall(VAO VAO1);




GLfloat vertices_border[] =
{
	
	//left bar 
	-1.03f, 1.03f, 0.0f, // upper left corner                  
	-0.93, 1.03f, 0.0f, // upper right corner                  
	-1.03f, -1.03f, 0.0f, // lower left corner
	-0.93, -1.03f, 0.0f, // lower rigth corner
	
	//right bar 
     1.03f, 1.03f, 0.0f, // upper left corner                  
	 0.93, 1.03f, 0.0f, // upper right corner                  
	 1.03f, -1.03f, 0.0f, // lower left corner
	 0.93, -1.03f, 0.0f, // lower rigth corner

	 //upper bar
	-1.03f, 0.93f, 0.0f, 
	 1.03f, 0.93f, 0.0f,

	 //lower bar
	-0.93, -1.03f, 0.0f,
	-0.93, -0.93f, 0.0f,
	 1.03f, -1.03f, 0.0f,
	 1.03f, -0.93f, 0.0f,
};

GLuint Indices_border[] =
{
	//left bar
	0, 1, 2,      // Lower left triangle   //4, 5, 6,
	2, 3, 1,  // Lower right triangle  //6, 7, 5,

	//right bar
    4, 5, 6,
	6, 7, 5,

	//upper bar
	0, 4, 8,
	4, 9, 8,

	//lower bar
	10, 11, 12,
    12, 13, 11,
};



















int main()
{
	
	
	
	
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);
	

	glfwSetKeyCallback(window, key_callback);
	(window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");



	                //// Snake \\\
	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(K1.vertices, K1.sizevertices);
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(K1.indices, K1.sizeindices);
	// Links VBO to VAO
    VAO1.LinkVBO(VBO1, 0);
	
	
	                 ////   Border    \\\
	
	
	VAO VAO2;
	VAO2.Bind();
	VBO VBO2(vertices_border, sizeof(vertices_border));
	EBO EBO2(Indices_border, sizeof(Indices_border));
	VAO2.LinkVBO(VBO2,0);
	


	              //// Fruit \\\\



	VAO VAO3;
	VAO3.Bind();
	VBO VBO3(f1.vertices, f1.sizevertices);
	EBO EBO3(f1.indices, f1.sizeindices);
	VAO3.LinkVBO(VBO3, 0);




	
	
	// Unbind all to prevent accidentally modifying them

VAO1.Unbind();
VBO1.Unbind();
EBO1.Unbind();

VAO2.Unbind();
VBO2.Unbind();
EBO2.Unbind();

VAO3.Unbind();
VBO3.Unbind();
EBO3.Unbind();




	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		




		//Drawing snake 
		addbricktosnake(VAO1,VAO3);
		MoveSnake(VAO1);
		Game_over_wall(VAO1);

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
	    // Tell OpenGL which Shader Program we want to use
		
		
		
		
		
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();


		// Draw primitives, number of indices, datatype of indices, index of indices
       	glDrawElements(GL_TRIANGLES, 300, GL_UNSIGNED_INT, 0);


		
		
		//Drawing border 
		
		VAO2.Bind();
		
		glDrawElements(GL_TRIANGLES, 300, GL_UNSIGNED_INT, 0);

		// fruit
		VAO3.Bind();
		glDrawElements(GL_TRIANGLES, 100, GL_UNSIGNED_INT, 0);





		shaderProgram.Activate();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();

	
	



	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
	
}





void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {


	if (key == GLFW_KEY_E && action == GLFW_PRESS)

	{
		//std::cout <<std::endl<< " " << K1.vertices[0] + 0.05 << " " << K1.vertices[1] - 0.05 <<std::endl;
		std::cout << std::endl << " " << std::fixed << std::setprecision(2) << K1.vertices[0] + 0.05 << " " << std::fixed << std::setprecision(2) << K1.vertices[1] - 0.05 << std::endl;
		//K1.X_y_addon_snake();
	}
    

	if (key == GLFW_KEY_W && action == GLFW_PRESS)

	{
		if (dont_go_back != 1)
		{
			register_to_move = 1;
			Direction_Movement = 1;
			dont_go_back = 0;
		}
	}


	if (key == GLFW_KEY_S && action == GLFW_PRESS)

	{
		if (dont_go_back != 0)
		{
			register_to_move = 1;
			Direction_Movement = 3;
			dont_go_back = 1;
		}
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)

	{
		if (dont_go_back != 3)
		{
			register_to_move = 1;
			Direction_Movement = 2;
			dont_go_back = 2;
		}
	}

	if (key == GLFW_KEY_D && action == GLFW_PRESS)

		if(dont_go_back!=2)
	    {
			register_to_move = 1;
			Direction_Movement = 4;
			dont_go_back = 3;
		}



	}

VAO addbricktosnake(VAO VAO1, VAO VAO3)
{
	if ((K1.x == f1.x)&&(K1.y==f1.y))
	{
		
		//new fruit location

		f1.Fruit_location();

		VAO3.Bind();

		VBO VBO3(f1.vertices, f1.sizevertices);
		EBO EBO3(f1.indices, f1.sizeindices);

		VAO3.LinkVBO(VBO3, 0);

		VAO3.Unbind();
		VBO3.Unbind();
		EBO3.Unbind();

		//grow Snake
		K1.Growsnake();
		VAO1.Bind();
		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(K1.vertices, K1.sizevertices);
		// Generates Element Buffer Object and links it to indices

		EBO EBO1(K1.indices, K1.sizeindices);

		VAO1.LinkVBO(VBO1, 0);

		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();




		
		register_to_grow = 0;
	
		return VAO1;
	}
	

	


	
}
VAO MoveSnake(VAO VAO1)
{

	
	if (register_to_move == 1)
	{

	

		K1.Movement(Direction_Movement);
		VAO1.Bind();
		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(K1.vertices, K1.sizevertices);
		// Generates Element Buffer Object and links it to indices

		EBO EBO1(K1.indices, K1.sizeindices);

		VAO1.LinkVBO(VBO1, 0);

		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();



	
		register_to_move = 0;
		Direction_Movement = 0;
		
		return VAO1;
	}
	
}


VAO Game_over_wall(VAO VAO1)
{
	



	//colision snake
	for (int i = 0; i != K1.vertNum; i = i + 12) {
		if (K1.vertices[0] == K1.vertices[12 + i] && K1.vertices[1] == K1.vertices[13 + i])
		{
			K1.reset_snake();
			K1.Number_additional_squares = 0;

			VAO1.Bind();
			// Generates Vertex Buffer Object and links it to vertices
			VBO VBO1(K1.vertices, K1.sizevertices);
			// Generates Element Buffer Object and links it to indices

			EBO EBO1(K1.indices, K1.sizeindices);

			VAO1.LinkVBO(VBO1, 0);

			VAO1.Unbind();
			VBO1.Unbind();
			EBO1.Unbind();
			return VAO1;
		}
	}
	
	
	
	
	
	//colisiont to border
	if ( ((K1.x == 100)||(K1.x==-100)) || ((K1.y == 100) || (K1.y == -100)))
	{

		K1.reset_snake();
		K1.Number_additional_squares = 0;
		
		VAO1.Bind();
		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(K1.vertices, K1.sizevertices);
		// Generates Element Buffer Object and links it to indices

		EBO EBO1(K1.indices, K1.sizeindices);

		VAO1.LinkVBO(VBO1, 0);

		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();
		return VAO1;
	}
     










}