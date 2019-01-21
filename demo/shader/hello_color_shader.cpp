#include "hello_color_shader.h"
#include <iostream>
#include "opengl_tools/OpenGLToolsWindow.h"
#include "../default_funcs.h"
#include "opengl_tools/OpenGLToolsShader.h"

void colorShaderWindowLoopCallback(OpenGLToolsWindow* window)
{

    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    window->shader->use();
    glBindVertexArray(window->data->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}
int hello_color_shader()
{
	std::cout << "Hello Color Shader!\n";

    OpenGLToolsWindow window = OpenGLToolsWindow::OpenGLToolsWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, frameCallback, "Hello Color Shader");

    window.shader = &OpenGLToolsShader::OpenGLToolsShader("demo/shaders/vertex_color_shader.shader", "demo/shaders/input_vec3_shader.shader");
    window.data = &OpenGLToolsVertexObject::OpenGLToolsVertexObject();
    
	float vertices[] = {
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
	};
    window.data->setVbo(sizeof(vertices), vertices, GL_STATIC_DRAW);
    window.data->setVao(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
    window.data->setVao(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

    window.invalidate();
    window.startWindowLoop(colorShaderWindowLoopCallback);

    window.data->destory();
    window.terminate();

	return 0;

}
