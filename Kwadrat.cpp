#include "Kwadrat.h"
#include <cstring>






Kwadrat::Kwadrat()
{
	vertNum = 12;
	indicNum = 6;
	
	Number_additional_squares = 0;
	sizeindices = sizeof(indices);
	vertices = new GLfloat[vertNum];
	indices = new GLuint[indicNum];
	x = 0;
	y = 0;



	//starting location 
	GLfloat local_vertices[] =
	{
		-0.05f, 0.05f, 0.0f, // upper left corner
		0.05f, 0.05f, 0.0f, // upper right corner
		-0.05f, -0.05f, 0.0f, // lower left corner
		0.05f, -0.05f, 0.0f, // lower rigth corner








	};

	this->sizevertices = sizeof(local_vertices);




	//starting indices
	GLuint Local_Indices[] =
	{
		0, 1, 2,      // Lower left triangle   //4, 5, 6,
		2, 3, 1,  // Lower right triangle  //6, 7, 5,


	};

	this->sizeindices = sizeof(Local_Indices);



	//writing local in to class object
	for (int i = 0; i != 12; i++)
	{
		this->vertices[i] = local_vertices[i];

	}


	for (int i = 0; i != 6; i++)
	{
		this->indices[i] = Local_Indices[i];
	}
 

};

void Kwadrat::reset_snake()
{



	delete[] vertices;
	delete[] indices;
	
	
	vertNum = 12;
	indicNum = 6;
	sizeindices = sizeof(indices);
	vertices = new GLfloat[vertNum];
	indices = new GLuint[indicNum];
	x = 0;
	y = 0;



	//starting location 
	GLfloat local_vertices[] =
	{
		-0.05f, 0.05f, 0.0f, // upper left corner
		0.05f, 0.05f, 0.0f, // upper right corner
		-0.05f, -0.05f, 0.0f, // lower left corner
		0.05f, -0.05f, 0.0f, // lower rigth corner








	};

	this->sizevertices = sizeof(local_vertices);




	//starting indices
	GLuint Local_Indices[] =
	{
		0, 1, 2,      // Lower left triangle   //4, 5, 6,
		2, 3, 1,  // Lower right triangle  //6, 7, 5,


	};

	this->sizeindices = sizeof(Local_Indices);



	//writing local in to class object
	for (int i = 0; i != 12; i++)
	{
		this->vertices[i] = local_vertices[i];

	}


	for (int i = 0; i != 6; i++)
	{
		this->indices[i] = Local_Indices[i];
	}








}

void Kwadrat::Growsnake()
{

	int x_other_square, y_other_square;
		int i = vertNum;
		int j = indicNum;
		// temporary vector for adding new part of snake
		GLfloat* Temp_vertices = new GLfloat[vertNum+12];
		GLuint* Temp_indic = new GLuint[indicNum + 6];
		
		
		for (int i = 0; i != vertNum; i++)
		{
			Temp_vertices[i] = this->vertices[i];
		}

		for (int i = 0; i != indicNum; i++)
		{
			Temp_indic[i] = this->indices[i];
		}

	   	//adding cordinate for new part                                   

		Temp_vertices[i] = Temp_vertices[i - 12] - 0.10f;  i++;
		Temp_vertices[i] = Temp_vertices[i - 12];     i++;
		Temp_vertices[i] = Temp_vertices[i - 12];    i++;

		Temp_vertices[i] = Temp_vertices[i - 12] - 0.10f; i++;         
		Temp_vertices[i] = Temp_vertices[i - 12];  i++;
		Temp_vertices[i] = Temp_vertices[i - 12];   i++;

		Temp_vertices[i] = Temp_vertices[i - 12] - 0.10f; i++;      
		Temp_vertices[i] = Temp_vertices[i - 12]; i++;
		Temp_vertices[i] = Temp_vertices[i - 12]; i++;

		Temp_vertices[i] = Temp_vertices[i - 12] - 0.10f; i++;
		Temp_vertices[i] = Temp_vertices[i - 12]; i++;
		Temp_vertices[i] = Temp_vertices[i - 12]; i++;

		 Temp_indic[j] = Temp_indic[j - 6] + 4; j++;
		 Temp_indic[j] = Temp_indic[j - 6] + 4; j++;
		 Temp_indic[j] = Temp_indic[j - 6] + 4; j++;

		 Temp_indic[j] = Temp_indic[j - 6] + 4; j++;
		 Temp_indic[j] = Temp_indic[j - 6] + 4; j++;
		 Temp_indic[j] = Temp_indic[j - 6] + 4; j++;


        //seting new size
		this->sizevertices = this->sizevertices + 48;
		this->sizeindices = this->sizeindices + 24;
		this->vertNum += 12;
		this->indicNum += 6;

		//delete old stuf
		delete[] this->vertices;
		this->vertices = Temp_vertices;
	  
		delete[] this->indices;
		this->indices = Temp_indic;
		
		Number_additional_squares++;

};


void Kwadrat::X_y_addon_snake()
{

	if (Number_additional_squares != 0)
	{

		double temp_x;
		double temp_y;
		int indic = 12;
		for (int i = 0; i != Number_additional_squares; i++)
		{
			temp_x=this->vertices[indic]+0.05;
			temp_y = this->vertices[indic+1] - 0.05;
 



			indic += 1;
			std::cout << temp_x << " " << temp_y << std::endl;
		}
	}
}

void Kwadrat::Movement(const int& Direction_Movement)
{

	

	GLfloat* Cordinate_of1_square=new GLfloat[vertNum];

	for (int i = 0; i != this->vertNum; i++)
	{
		Cordinate_of1_square[i] = this->vertices[i];
	}
		

	//up
	if (Direction_Movement == 1)
	{




		this->vertices[1] += 0.10f;
		this->vertices[4] += 0.10f;
		this->vertices[7] += 0.10f;
		this->vertices[10] += 0.10f;
		for (int i = 12; i != this->vertNum; i++)
		{
			this->vertices[i] = Cordinate_of1_square[i - 12];
		}
		y = y + 10;

		


	}
	
	//left
	if (Direction_Movement == 2)
	{
		this->vertices[0] -= 0.10f;
		this->vertices[3] -= 0.10f;
		this->vertices[6] -= 0.10f;
		this->vertices[9] -= 0.10f;

		for (int i = 12; i != this->vertNum; i++)
		{
			this->vertices[i] = Cordinate_of1_square[i - 12];
		}
		x = x - 10;

		



	}
	//down
	if (Direction_Movement == 3)
	{
		this->vertices[1] -= 0.10f;
		this->vertices[4] -= 0.10f;
		this->vertices[7] -= 0.10f;
		this->vertices[10] -= 0.10f;

		for (int i = 12; i != this->vertNum; i++)
		{
			this->vertices[i] = Cordinate_of1_square[i - 12];
		}
		y = y - 10;


		




	}
	
	
	//right 
	if (Direction_Movement == 4)
	{
		this->vertices[0] += 0.10f;
		this->vertices[3] += 0.10f;
		this->vertices[6] += 0.10f;
		this->vertices[9] += 0.10f;

		for (int i = 12; i != this->vertNum; i++)
		{
			this->vertices[i] = Cordinate_of1_square[i-12];
		}
		

		x = x + 10;

		



	}


//	for (int i = 12; i != sizevertices; i++)
	//{
		//this->vertices[i] = this->vertices[i] - 12;
	//}
	delete[] Cordinate_of1_square;
		
	

}
