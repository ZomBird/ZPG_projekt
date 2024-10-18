#include "Shader.h"

Shader::Shader(const char* vertexSource, const char* fragmentSource) {
    GLuint vertexShader, fragmentShader;
    CompileShader(vertexSource, GL_VERTEX_SHADER, vertexShader);
    CompileShader(fragmentSource, GL_FRAGMENT_SHADER, fragmentShader);
    LinkProgram(vertexShader, fragmentShader);
}

void Shader::CompileShader(const char* source, GLenum shaderType, GLuint& shaderID) {
    shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &source, NULL);
    glCompileShader(shaderID);

    // Zkontroluj chyby kompilace
    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        fprintf(stderr, "ERROR: Shader compilation failed: %s\n", infoLog);
    }
}

void Shader::LinkProgram(GLuint vertexShader, GLuint fragmentShader) {
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Zkontroluj chyby linkování (pøidej kontrolu chyb zde)
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        fprintf(stderr, "ERROR: Program linking failed: %s\n", infoLog);
    }
}

void Shader::Use() {
    glUseProgram(shaderProgram);
}
