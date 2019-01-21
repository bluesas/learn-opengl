#include "hello_trangle.h"
#include <iostream>
#include "opengl_tools/OpenGLToolsWindow.h"
#include "../default_funcs.h"
#include "opengl_tools/OpenGLToolsShader.h"

void trangleLoopCallback(OpenGLToolsWindow* window)
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    window->shader->use();
    glBindVertexArray(window->data->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int hello_trangle()
{
	std::cout << "Hello Trangle!\n";

    OpenGLToolsWindow window = OpenGLToolsWindow::OpenGLToolsWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, frameCallback, "Hello Trangle");
	
    OpenGLToolsShader shader = OpenGLToolsShader::OpenGLToolsShader("shaders/vertex_shader.shader", "shaders/fragment_shader.shader");

	float vertices[] = {
		-0.5f, -0.5f, 0.7f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

    window.shader = &shader;
    window.data = &OpenGLToolsVertexObject::OpenGLToolsVertexObject();
    window.data->setVbo(sizeof(vertices), vertices, GL_STATIC_DRAW);
    window.data->setVao(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

    window.invalidate();
    window.startWindowLoop(trangleLoopCallback);

    window.data->destory();
	window.terminate();

	return 0;

}
