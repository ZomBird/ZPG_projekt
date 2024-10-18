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
      
    void Run(); // Spu�t�n� aplikace

private:
    GLFWwindow* window; // Ukazatel na okno
    std::vector<Model> models; // Seznam model�
    std::vector<Shader> shaders; // Seznam shader program�

    void Initialize(); // Inicializace OpenGL
    void Render(); // Hlavn� vykreslovac� smy�ka

    void processInput();
};