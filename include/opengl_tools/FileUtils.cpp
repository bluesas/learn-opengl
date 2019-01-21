#include "FileUtils.h"

std::string FileUtils::readFileAsString(const char* filePath)
{
    // 1. 从文件路径中读取内容
    std::ifstream file;

    // 保证ifstream对象可以抛出异常：
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // 打开文件
        file.open(filePath);
        file.is_open();
        std::stringstream stream;

        // 读取文件的缓冲内容到数据流中
        stream << file.rdbuf();

        // 关闭文件处理器
        file.close();

        // 转换数据流到string
        return stream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        std::cout << filePath << std::endl;
        std::cout << e.what() << std::endl;
        return NULL;
    }
}

FileUtils::FileUtils()
{
}

FileUtils::~FileUtils()
{
}