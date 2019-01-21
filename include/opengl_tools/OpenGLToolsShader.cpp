#include "OpenGLToolsShader.h"

OpenGLToolsShader::OpenGLToolsShader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    //vertex
    unsigned int vertexShader = get_shader_from_file(vertexPath, GL_VERTEX_SHADER);

    // fragment
    unsigned int fragmentShader = get_shader_from_file(fragmentPath, GL_FRAGMENT_SHADER);

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);

    linkProgram(id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
};

void OpenGLToolsShader::use()
{
    glUseProgram(id);
};

// uniform¹¤¾ßº¯Êý
void OpenGLToolsShader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
};

void OpenGLToolsShader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
};

void OpenGLToolsShader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
};

void OpenGLToolsShader::compileShader(GLuint shader, GLsizei count, const GLchar* const* shaderSourcePointer, const GLint* length)
{
    const int log_length = 512;
    int success;
    char infoLog[log_length];

    glShaderSource(shader, count, shaderSourcePointer, length);
    glCompileShader(shader);
    // check for shader compile errors
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, log_length, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void OpenGLToolsShader::linkProgram(GLuint program)
{
    const int log_length = 512;
    int success;
    char infoLog[log_length];

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, log_length, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

unsigned int OpenGLToolsShader::get_shader_from_file(const char* path, GLenum type)
{

    std::string str = FileUtils::readFileAsString(path);
    const char* shaderSource = str.c_str();

    unsigned int shader = glCreateShader(type);
    compileShader(shader, 1, &shaderSource, NULL);

    return shader;
}
