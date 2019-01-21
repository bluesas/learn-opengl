#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include "FileUtils.h"

class OpenGLToolsShader
{
public:

	unsigned int id;

    OpenGLToolsShader() {};
	OpenGLToolsShader(const GLchar* vertexPath, const GLchar* fragmentPath);

	void use();

	// uniform工具函数
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

    static void compileShader(GLuint shader, GLsizei count, const GLchar* const* shaderSourcePointer, const GLint* length);

    static void linkProgram(GLuint program);

	~OpenGLToolsShader() {};

private:
    unsigned int get_shader_from_file(const char* path, GLenum type);
};

#endif
