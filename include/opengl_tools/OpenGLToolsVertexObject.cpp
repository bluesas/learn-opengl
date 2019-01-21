#include "OpenGLToolsVertexObject.h"



OpenGLToolsVertexObject::OpenGLToolsVertexObject()
{
    vao = 0;
    vbo = 0;
    ebo = 0;
}


OpenGLToolsVertexObject::~OpenGLToolsVertexObject()
{
}

void OpenGLToolsVertexObject::bindVertexArray()
{
    if (!vao || vao == NULL)
    {
        glGenVertexArrays(1, &vao);
    }
    glBindVertexArray(vao);
}

void OpenGLToolsVertexObject::setVao(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
    bindVertexArray();
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}


void OpenGLToolsVertexObject::setVbo(GLsizeiptr size, const void *data, GLenum usage)
{
    bindVertexArray();

    if (!vbo || vbo == 0)
    {
        glGenBuffers(1, &vbo);
    }
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);

}


void OpenGLToolsVertexObject::setEbo(GLsizeiptr size, const void *data, GLenum usage)
{
    bindVertexArray();
    if (!ebo || ebo == NULL)
    {
        glGenBuffers(1, &ebo);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
}

void OpenGLToolsVertexObject::destory()
{
    if (vao && vao > 0)
    {
        glDeleteVertexArrays(1, &vao);
    }
    if (vbo && vbo > 0)
    {
        glDeleteBuffers(1, &vbo);
    }
    if (ebo && ebo > 0)
    {
        glDeleteBuffers(1, &ebo);
    }
}
