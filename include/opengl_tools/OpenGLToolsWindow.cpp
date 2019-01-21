#include "OpenGLToolsWindow.h"

OpenGLToolsWindow::OpenGLToolsWindow(int width, int height,
    GLFWframebuffersizefun frameCallback,
    const char* title,
    int closeWindowKey, int left, int top)
{
    this->width = width;
    this->height = height;
    this->title = title;
    this->left = left;
    this->top = top;
    this->frameCallback = frameCallback;
    this->closeWindowKey = closeWindowKey;

    this->validate = true;
    initWindow();
}

int OpenGLToolsWindow::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->glwindow = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
    if (this->glwindow == NULL)
    {
        std::cout << "Failed to create Window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(this->glwindow);
    glfwSetFramebufferSizeCallback(this->glwindow, this->frameCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(this->left, this->top, this->width, this->height);

    return 0;
}

void OpenGLToolsWindow::startWindowLoop(void(*windowLoopCallback)(OpenGLToolsWindow* window))
{ 
    while (!glfwWindowShouldClose(glwindow))
    {
        processInput(this->glwindow);

        if (!isValidate() && (windowLoopCallback != NULL))
        {
            this->validate = true;
            (windowLoopCallback)(this);
            glfwSwapBuffers(this->glwindow);
        }

        glfwPollEvents();

    }
}

void OpenGLToolsWindow::terminate()
{
    glfwTerminate();
}

void OpenGLToolsWindow::invalidate()
{
    this->validate = false;
}

bool OpenGLToolsWindow::isValidate()
{
    return this->validate;
}


void OpenGLToolsWindow::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, this->closeWindowKey) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

OpenGLToolsWindow::~OpenGLToolsWindow()
{
}