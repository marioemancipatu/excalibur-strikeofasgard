#pragma once
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<vector>


// Include GLEW and GLFW
#include "glew/glew.h"
#include "glfw/glfw3.h"

// Include GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// Include our helper function for loading shaders
#include "Shaders/Utils/shaderLoader.hpp"

// Global variables
#include "Globals/globals.hpp"

float deltaTime = 0.0002f;
float lastFrame = 0.0f;

//information about each character in vector
struct Character {
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec4 color;
};

std::vector<Character> characters;

void thor_movement(GLFWwindow* window)
{
	float speed = 1.0f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		characters[0].position.y += speed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		characters[0].position.y -= speed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		characters[0].position.x -= speed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		characters[0].position.x += speed;
	}
}


// Callback function for cursor position
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << "The mouse cursor is: " << xpos << " " << ypos << std::endl;

	// TODO Ex 8
	// Don't forget that OpenGL coordinates are between -1,-1 and 1,1
}



void window_callback(GLFWwindow* window, int new_width, int new_height)
{
	glViewport(0, 0, new_width, new_height);
}

int main(void)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		(void)getchar();
		return -1;
	}

#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(windowWidth, windowHeight, "Lab 3", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.");
		(void)getchar();
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		(void)getchar();
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, windowWidth, windowHeight);

	//glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClearColor(0.0f, 0.6f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	GLuint programID = LoadShaders("SimpleVertexShader.vert", "SimpleFragmentShader.frag");

	GLfloat vertices[] = {
		//tr = top right
		//tl = top left
		//br = bottom right
		//bl = bottom left

		//CHARACTER
		//head start = 0
		0.04f,  0.03f, 0.0f,	// top right
		0.04f, -0.05f, 0.0f,	// bottom right
		-0.04f, -0.05f, 0.0f,	// bottom left
		-0.04f,  0.03f, 0.0f,	// top left 

		//neck start = 4
		0.02f, -0.05f, 0.0f,	//tr
		-0.02f, -0.05f, 0.0f,	//tl
		0.02f, -0.10f, 0.0f,	//br
		-0.02f, -0.10f, 0.0f,	//bl

		//body start = 8
		0.05f, -0.10f, 0.0f,	//tr
		-0.05f, -0.10f, 0.0f,	//tl
		0.05f, -0.30f, 0.0f,	//br
		-0.05f, -0.30f, 0.0f,	//bl
		//width = 10

		//legs start = 12
		0.01f, -0.30f, 0.0f,	//inside right leg
		0.05f, -0.50f, 0.0f,	//br right leg
		0.01f, -0.50f, 0.0f,	//bl right leg
		-0.01f, -0.30f, 0.0f,	//inside left leg
		-0.05f, -0.50f, 0.0f,	//bl left leg
		-0.01f, -0.50f, 0.0f,	//br left leg

		//arms start = 18
		//right arm
		0.12f, -0.28f, 0.0f,	//br
		0.09f, -0.30f, 0.0f,	//bl
		0.02f, -0.12f, 0.0f,	//tr
		//left arm
		-0.12f, -0.28f, 0.0f,	//bl
		-0.09f, -0.30f, 0.0f,	//br
		-0.02f, -0.12f, 0.0f,	//tr

		//ALTAR
		//floor start = 24
		0.2f, 0.5f, 0.0f,	//tl
		0.4f, 0.5f, 0.0f,	//tr
		0.2f, 0.45f, 0.0f,	//bl
		0.4f, 0.45f, 0.0f,	//br

		//left pillar start = 28
		0.22f, 0.8f, 0.0f,	//tl
		0.24f, 0.8f, 0.0f,	//tr
		0.22f, 0.5f, 0.0f,	//bl
		0.24f, 0.5f, 0.0f,	//br

		//right pillar start = 32
		0.36f, 0.8f, 0.0f,	//tl
		0.38f, 0.8f, 0.0f,	//tr
		0.36f, 0.5f, 0.0f,	//bl
		0.38f, 0.5f, 0.0f,	//br

		//left top part start = 36
		0.21f, 0.83f, 0.0f, //tl
		0.25f, 0.83f, 0.0f, //tr
		0.21f, 0.8f, 0.0f, //bl
		0.25f, 0.8f, 0.0f, //br

		//right top part start = 40
		0.35f, 0.83f, 0.0f, //tl
		0.39f, 0.83f, 0.0f, //tr
		0.35f, 0.8f, 0.0f, //bl
		0.39f, 0.8f, 0.0f, //br

	};

	GLuint indices[] = {	// Note that we start from 0
		//head
		0, 3, 1,
		1, 3, 2,

		//neck
		4, 5, 6,
		5, 6, 7,

		//body
		8, 9, 10,
		9, 10, 11,

		//left leg
		11, 15, 17,
		11, 17, 16,

		//right leg
		10, 12, 14,
		10, 13, 14,

		//right arm
		8, 18, 19,
		8, 19, 20,

		//left arm
		9, 21, 22,
		9, 22, 23,

		//altar floor
		24, 25, 27,
		24, 26, 27,

		//altar left pillar
		28, 29, 31,
		28, 30, 31,

		//altar right pillar
		32, 33, 35,
		32, 34, 35,

		//altar left top part
		36, 37, 39,
		36, 38, 39,

		//altar right top part
		40, 41, 43,
		40, 42, 43,
	};

	// Create VAO, VBO and IBO
	GLuint vao, vbo, ibo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	// Bind VAO
	glBindVertexArray(vao);

	// Bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind IBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Describe the data in the buffer
	// This will be accesible in the shaders
	glVertexAttribPointer
	(
		0,                    // attribute 0, must match the layout location in the shader
		3,                    // size of each attribute (3 floats)
		GL_FLOAT,             // type of data
		GL_FALSE,             // should be normalized?
		3 * sizeof(GL_FLOAT), // stride for this attribute
		0					  // initial offset for array buffer
	);
	glEnableVertexAttribArray(0);

	characters = {
		//Thor
		{
			glm::vec3(-0.6f, 0.2f, 0.0f),
			glm::vec3(0.4f, 0.5f, 1.0f),
			glm::vec4(0.55f, 0.0f, 0.0f, 1.0f)
		},

		//Dr. Strange
		{
			glm::vec3(-0.2f, 0.2f, 0.0f),
			glm::vec3(0.4f, 0.5f, 1.0f),
			glm::vec4(0.0f, 0.0f, 0.6f, 1.0f)
		},

		//Enemy 1
		{
			glm::vec3(0.2f, 0.2f, 0.0f),
			glm::vec3(0.4f, 0.5f, 1.0f),
			glm::vec4(0.35f, 0.5f, 0.3f, 1.0f)
		},

		//Enemy 2
		{
			glm::vec3(0.6f, 0.2f, 0.0f),
			glm::vec3(0.4f, 0.5f, 1.0f),
			glm::vec4(0.2f, 0.35f, 0.21f, 1.0f)
		},
	};


	// Create identity matrix for transforms
	glm::mat4 trans(1.0f);

	// Some different positions for later
	glm::vec3 positions[] = {
		glm::vec3(0.0f,  0.0f,  0),
		glm::vec3(0.2f,  0.5f, 0),
		glm::vec3(-0.15f, -0.22f, 0),
		glm::vec3(-0.38f, -0.2f, 0),
		glm::vec3(0.24f, -0.4f, 0),
		glm::vec3(-0.17f,  0.3f, 0),
		glm::vec3(0.23f, -0.2f, 0),
		glm::vec3(0.15f,  0.2f, 0),
		glm::vec3(0.15f,  0.7f, 0),
		glm::vec3(-0.13f,  0.1f, 0)
	};

	// Set a callback for handling mouse cursor position
	// Decomment the following line for a cursor position change callback example
	// glfwSetCursorPosCallback(window, cursor_position_callback);

	// TODO Ex4
	// Set callback for window resizing
	glfwSetFramebufferSizeCallback(window, window_callback);


	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	unsigned int transformLoc2 = glGetUniformLocation(programID, "color");

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		thor_movement(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(programID);

		// Apply z-axis rotation to our transform matrix
		//trans = glm::rotate(trans, 0.5f, glm::vec3(0.0, 0.0, 1.0));

		glBindVertexArray(vao);

		glm::mat4 altarTrans(1.0f);
		altarTrans = glm::translate(altarTrans, glm::vec3(-0.3f, -0.3f, 0.0f));
		altarTrans = glm::scale(altarTrans, glm::vec3(1.0f, 1.0f, 1.0f));

		glm::vec4 altarColor(0.45f, 0.45f, 0.5f, 1.0f);

		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(altarTrans));
		glUniform4fv(transformLoc2, 1, glm::value_ptr(altarColor));

		glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, (void*)(42 * sizeof(GLuint)));

		for (size_t i = 0; i < characters.size(); i++)
		{
			glm::mat4 trans(1.0f);
			trans = glm::translate(trans, characters[i].position);
			trans = glm::scale(trans, characters[i].scale);

			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
			glUniform4fv(transformLoc2, 1, glm::value_ptr(characters[i].color));

			glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, 0);
		}

		//unsigned int transformLoc = glGetUniformLocation(programID, "transform");
		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
		//
		//unsigned int transformLoc2 = glGetUniformLocation(programID, "color");
		//glm::vec4 color = glm::vec4(0.5f, 0, 0.5f, 1.0);
		//glUniform4fv(transformLoc2, 1, glm::value_ptr(color));

		//glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, 0);
	}

	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(programID);

	glfwTerminate();

	return 0;
}
