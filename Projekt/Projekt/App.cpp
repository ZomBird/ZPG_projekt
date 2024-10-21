#include "App.h"
App::App() {
	if (!glfwInit()) {
		std::cerr << "ERROR: could not start GLFW3\n";
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 600, "ZPG - Application", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Nastavení barvy pozadí na bílou
	glewExperimental = GL_TRUE;
	glewInit();
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}
App::~App() {
	glfwDestroyWindow(window);
	glfwTerminate();
}
void App::addObject(Model& model, Shader& shader) {

	shaders.push_back(shader);
	models.push_back(model);
}
void App::Render() {
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Vykresli trojúhelník
		for (int i = 0; i < models.size(); i++)
		{
			shaders[i].Use();  // Použij shader pro trojúhelník
			models[i].Draw();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
void App::Run() {
	Render();
}