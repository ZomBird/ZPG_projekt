#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

#include "Models.h"
#include  "Shader.h"
class App
{
public:
	App();
	~App();
      
    void Run(); // Spuštìní aplikace

private:
    GLFWwindow* window; // Ukazatel na okno
    std::vector<Model> models; // Seznam modelù
    std::vector<Shader> shaders; // Seznam shader programù

    void Initialize(); // Inicializace OpenGL
    void Render(); // Hlavní vykreslovací smyèka

    void processInput();
};