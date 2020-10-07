//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___FILELOADER_H
#define VXL___FILELOADER_H

#include <filesystem>

class FileLoader {
    std::filesystem::path rootPath;

public:
    FileLoader(const char*);

    std::string loadFileAsString(const char* filePath) ;
};


#endif //VXL___FILELOADER_H
