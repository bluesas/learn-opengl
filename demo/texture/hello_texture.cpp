#include "hello_texture.h"

#include <iostream>
#include "opengl_tools/OpenGLToolsWindow.h"
#include "../default_funcs.h"
#include "opengl_tools/OpenGLToolsShader.h"

void textureWindowLoopCallback(OpenGLToolsWindow* window)
{

    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    window->shader->use();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBindVertexArray(window->data->vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

int hello_texture()
{
    std::cout << "Hello Trangles!\n";

    OpenGLToolsWindow window = OpenGLToolsWindow::OpenGLToolsWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, frameCallback, "Hello Trangle");

    window.shader = &OpenGLToolsShader::OpenGLToolsShader("demo/shaders/vertex_shader.shader", "demo/shaders/fragment_shader.shader");

    window.data = &OpenGLToolsVertexObject::OpenGLToolsVertexObject();
    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // ÓÒÉÏ½Ç
        0.5f, -0.5f, 0.0f,  // ÓÒÏÂ½Ç
        -0.5f, -0.5f, 0.0f, // ×óÏÂ½Ç
        -0.5f, 0.5f, 0.0f   // ×óÉÏ½Ç

    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    window.data->setVbo(sizeof(vertices), vertices, GL_STATIC_DRAW);
    window.data->setEbo(sizeof(indices), indices, GL_STATIC_DRAW);
    window.data->setVao(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    window.invalidate();
    window.startWindowLoop(textureWindowLoopCallback);

    window.data->destory();
    window.terminate();

    return 0;

}