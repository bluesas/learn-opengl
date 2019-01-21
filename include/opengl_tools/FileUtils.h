#pragma once

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class FileUtils
{
public:
    static std::string readFileAsString(const char* filePath);
    FileUtils();
    ~FileUtils();

private:

};

#endif