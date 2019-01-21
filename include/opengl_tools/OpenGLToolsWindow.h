#pragma once

#ifndef OPENGL_TOOLS_WINDOW_H
#define OPENGL_TOOLS_WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "OpenGLToolsShader.h"
#include "OpenGLToolsVertexObject.h"

class OpenGLToolsWindow
{
public:

    OpenGLToolsWindow(int width, int height,
        GLFWframebuffersizefun frameCallback,
        const char* title, int closeWindowKey = GLFW_KEY_ESCAPE, int left = 0, int top = 0);
    
    int width;
    int height;
    int left;
    int top;
    const char* title;

    GLFWwindow* glwindow;
    OpenGLToolsVertexObject* data;
    OpenGLToolsShader* shader;

    ~OpenGLToolsWindow();

    void startWindowLoop(void(*windowLoopCallback)(OpenGLToolsWindow* window));

    void terminate();

    void invalidate();
    bool isValidate();

private:

    GLFWframebuffersizefun frameCallback;
    bool validate;

    int closeWindowKey;

    int initWindow();

    void processInput(GLFWwindow* window);
};
#endif // !OPENGL_TOOLS_WINDOW_H
