// gravity.cpp : definisce il punto di ingresso dell'applicazione console.
//

//#define GLEW_STATIC
#include "stdafx.h"
//#include <string>
//#include <gl\GL.h>
#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Force.h"
#include "Planet.h"
#include "Calcs.h"
#include "GLEW\GL\glew.h"
#include "GLFW\glfw3.h"
using namespace std;

const int N = 3;


int main()
{

	// WINDOW CREATION
	glfwInit();
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed

	glfwMakeContextCurrent(window);
	// --
	glewExperimental = GL_TRUE;
	glewInit();

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float vertices[] = {
		0.0f,0.5f,	1.0f,0.0f,0.0f,
		0.5f,-0.5f,	0.0f,1.0f,0.0f,
		-0.5f,-0.5f,0.0f,0.0f,1.0f
	};
	// VBO CREATION

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//GLSL SHADERS
	const char* vertexSource = R"glsl(
		#version 150 core
		in vec2 position;
		in vec3 color;
		out vec3 Color;

		void main()
		{
			Color=color;
			gl_Position = vec4(position, 0.0, 1.0);
		})glsl";


	const GLchar* fragmentSource = R"glsl(
		#version 150 core
		in vec3 Color;
		out vec4 outColor;
		void main()
		{
			outColor = vec4(Color, 1.0);
		}
	)glsl";

	//Vertexshader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) cout << "Errore compilazione shader 1";
	//fragmentshader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) cout << "Errore compilazione shader 2";

	//combine the two in a programshader
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	//Link it
	glLinkProgram(shaderProgram);
	//use it
	glUseProgram(shaderProgram);

	//Specify how data is to be interpreted
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), 0);
	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));




	int i = 0;
	Planet a[N] = { Planet(Vector(1.0f, 1.0f, 1.0f), Vector(0.0f, 0.0f, 0.0f), 100.0f, 1.0f) ,\
					Planet(Vector(100.0f, 100.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10.0f, 1.0f) ,\
					Planet(Vector(100.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10.0f, 1.0f) };
	while (!glfwWindowShouldClose(window))
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		/*
		cout << "\n  x: " << a[0].position.x << "  y: " << a[0].position.y << "  z: " << a[0].position.z;
		cout << "\t Bx: " << a[1].position.x << "  y: " << a[1].position.y << "  z: " << a[1].position.z;
		cout << "\t Cx: " << a[2].position.x << "  y: " << a[2].position.y << "  z: " << a[2].position.z;

		for (i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (j != i) a[i].Addforce(Gravity(a[i], a[j]));
			}
		}	   //Gravity
		for (i = 0; i < N; i++)
		{
			a[i].Update();
		}		//Update
		*/
	}
	glfwTerminate();

}