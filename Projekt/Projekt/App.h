#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


#include "Model.h"
#include  "Shader.h"
class App
{
public:
	App();
	~App();
      
    void Run(); // Spu�t�n� aplikace
    void addObject(Model& model, Shader& shader);

private:
    GLFWwindow* window; // Ukazatel na okno
    std::vector<Model> models; // Seznam model�
    std::vector<Shader> shaders; // Seznam shader program�
     // Inicializace OpenGL
    void Render(); // Hlavn� vykreslovac� smy�ka

};