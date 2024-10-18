#ifndef MODEL_H
#define MODEL_H
#include <GL/glew.h>
#include <iostream>
class Models {
public:
    Models(float* vertices, size_t size);  // Konstruktor pøijímá pole vrcholù a jejich velikost
    ~Models();  // Destruktor
    void Draw();  // Metoda pro vykreslení modelu

private:
    GLuint VAO, VBO;  // OpenGL objekty
};

#endif