#pragma once
#ifndef OPENGL_TOOLS_VERTEX_OBJECT_H
#define OPENGL_TOOLS_VERTEX_OBJECT_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class OpenGLToolsVertexObject
{
public:
    OpenGLToolsVertexObject();
    ~OpenGLToolsVertexObject();
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;

    void bindVertexArray();
    void setVao(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    void setVbo(GLsizeiptr size, const void *data, GLenum usage);
    void setEbo(GLsizeiptr size, const void *data, GLenum usage);

    void destory();

};

#endif // !OPENGL_TOOLS_VERTEX_OBJECT_H



