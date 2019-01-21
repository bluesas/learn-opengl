#include "default_funcs.h"

void frameCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}