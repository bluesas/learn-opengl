#include "FileUtils.h"

std::string FileUtils::readFileAsString(const char* filePath)
{
    // 1. ���ļ�·���ж�ȡ����
    std::ifstream file;

    // ��֤ifstream��������׳��쳣��
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // ���ļ�
        file.open(filePath);
        file.is_open();
        std::stringstream stream;

        // ��ȡ�ļ��Ļ������ݵ���������
        stream << file.rdbuf();

        // �ر��ļ�������
        file.close();

        // ת����������string
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