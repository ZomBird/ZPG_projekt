#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shader {
public:
    Shader(const char* vertexSource, const char* fragmentSource);

    void Use(); // aktivuje shader

private:
    GLuint shaderProgram;
    void CompileShader(const char* source, GLenum shaderType, GLuint& shaderID);
    void LinkProgram(GLuint vertexShader, GLuint fragmentShader);
};