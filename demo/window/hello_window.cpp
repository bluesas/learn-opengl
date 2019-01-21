#include "hello_window.h"
#include <iostream>
#include "opengl_tools/OpenGLToolsWindow.h"
#include "../default_funcs.h"

void windowLoopCallback(OpenGLToolsWindow* window)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int hello_window()
{
	std::cout << "Hello Window!\n";

    OpenGLToolsWindow window = OpenGLToolsWindow::OpenGLToolsWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, frameCallback, "Hello Window");

    window.invalidate();
    window.startWindowLoop(windowLoopCallback);
	
	window.terminate();

	return 0;

}
