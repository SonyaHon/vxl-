//
// Created by Volkov Pavel on 07.10.2020.
//

#include "FileLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

FileLoader::FileLoader(const char* assetPath) {
    rootPath = std::filesystem::current_path().parent_path() / assetPath;
}

std::string FileLoader::loadFileAsString(const char *filePath) {
    std::ifstream file;
    file.open((rootPath / filePath).c_str());
    std::stringstream fileStream;
    fileStream << file.rdbuf();
    file.close();

   return fileStream.str();
}
