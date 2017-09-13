// gravity.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
//#include <string>
#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Force.h"
#include "Planet.h"
#include "Calcs.h"
//#include "GLFW\glfw3.h"
using namespace std;

const int N = 3;


int main()
{
	/*
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr); // Windowed

	glfwMakeContextCurrent(window);

	float vertices[] = {
		0.0f,0.5f,
		0.5f,-0.5f,
		-0.5f,-0.5f
	};

	Gluint vbo;
	glGenBuffers(1, &vbo);
	*/

	int i = 0;
	Planet a[N] = { Planet(Vector(1.0f, 1.0f, 1.0f), Vector(0.0f, 0.0f, 0.0f), 100.0f, 1.0f) ,\
					Planet(Vector(100.0f, 100.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10.0f, 1.0f) ,\
					Planet(Vector(100.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10.0f, 1.0f) };
		while (true)//(!glfwWindowShouldClose(window))
		{
			/*
			glfwSwapBuffers(window);
			glfwPollEvents();
			*/


			///*
			cout << "\n  x: " << a[0].position.x << "  y: " << a[0].position.y << "  z: " << a[0].position.z;
			cout << "\t Bx: " << a[1].position.x << "  y: " << a[1].position.y << "  z: " << a[1].position.z;
			cout << "\t Cx: " << a[2].position.x << "  y: " << a[2].position.y << "  z: " << a[2].position.z;
			//*/
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
		}
		//glfwTerminate();

}