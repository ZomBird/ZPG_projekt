#ifndef MODEL_H
#define MODEL_H
#include <GL/glew.h>
#include <iostream>
class Model {
public:
	Model(float* vertices, size_t size, int vertexCount);  // Konstruktor p�ij�m� pole vrchol� a jejich velikost
	~Model();  // Destruktor
	void Draw();  // Metoda pro vykreslen� modelu

private:
	GLuint VAO, VBO;  // OpenGL objekty
	int vertexCount;
};

#endif