﻿//Include GLFW  
#include <GL/glew.h>
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Model.h"
#include "Shader.h"
#include "App.h"

float points[] = {
	0.0f, 0.5f, -0.5f,   // Trojúhelník blíže ke kameře
	0.5f, -0.5f, -0.5f,
   -0.5f, -0.5f, -0.5f
};

float rectangleVertices[] = {
	-0.5f, 0.5f, -1.0f,   // Obdélník dále od kamery
	 0.5f, 0.5f, -1.0f,
	-0.5f, -0.5f, -1.0f,
	 0.5f, 0.5f, -1.0f,
	 0.5f, -0.5f, -1.0f,
	-0.5f, -0.5f, -1.0f
};

const char* vertex_shader =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"void main () {"
"     gl_Position = vec4 (vp, 1.0);"
"}";

const char* fragment_shader1 =
"#version 330\n"
"out vec4 frag_colour;"
"void main () {"
"    frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
"}";

const char* fragment_shader2 =
"#version 330\n"
"out vec4 frag_colour;"
"void main () {"
"    frag_colour = vec4(0.0, 0.5, 0.5, 1.0);"
"}";

static void error_callback(int error, const char* description) { fputs(description, stderr); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

static void window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

static void window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

static void window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow* window, double x, double y) { printf("cursor_callback \n"); }

static void button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}
//GLM test

// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

// Camera matrix
glm::mat4 View = glm::lookAt(
	glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
	glm::vec3(0, 0, 0), // and looks at the origin
	glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
);
// Model matrix : an identity matrix (model will be at the origin)
glm::mat4 Models = glm::mat4(1.0f);



int main()
{
	// Vytvoření shaderu
	App app;
	Model model01(points, sizeof(points), 3);
	Shader shader01(vertex_shader, fragment_shader1);
	Shader shader02(vertex_shader, fragment_shader2);
	Model regtangle(rectangleVertices, sizeof(rectangleVertices), 6);



	app.addObject(regtangle, shader01);
	app.addObject(model01, shader02);

	app.Run();



	exit(EXIT_SUCCESS);
}
