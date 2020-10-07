//
// Created by volko on 06.10.2020.
//

#ifndef VXL___SHADER_H
#define VXL___SHADER_H

#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../components/Transform.h"

struct ShaderData {
    GLenum type;
    std::filesystem::path path;
};

struct Shader {
    GLuint id;
};

Shader createShader(const std::vector<ShaderData>& shadersData) {
    GLuint programId = glCreateProgram();
    std::vector<GLuint> shaderIds = std::vector<GLuint>(shadersData.size());

    std::filesystem::path root = std::filesystem::current_path().parent_path() / "res/shaders";

    for (auto &i : shadersData) {
        std::ifstream shaderFile;
        shaderFile.open((root / i.path).c_str());
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();

        std::string shaderString = shaderStream.str();
        const char *shaderSource = shaderString.c_str();

        unsigned int shaderId = glCreateShader(i.type);
        glShaderSource(shaderId, 1, &shaderSource, nullptr);
        glCompileShader(shaderId);

        int success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
            std::cout << "Error compiling shader " << i.path << " Error:\n" << infoLog << std::endl;
            exit(-1);
        }

        shaderIds.push_back(shaderId);
        glAttachShader(programId, shaderId);
    }

    glLinkProgram(programId);
    int success;
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(programId, 512, nullptr, infoLog);
        std::cout << "Error linking program Error:\n" << infoLog << std::endl;
        exit(-1);
    }

    for (unsigned int shaderId : shaderIds) {
        glDeleteShader(shaderId);
    }

    return Shader{programId};
}

void useShader(const Shader *shader) {
    glUseProgram(shader->id);
}

void stopUsingShader() {
    glUseProgram(0);
}

GLuint getUniformLocation(const Shader *shader, const char *location) {
    return glGetUniformLocation(shader->id, location);
}

void addFloatUniform(const Shader *shader, const char *location, float value) {
    glUniform1f(getUniformLocation(shader, location), value);
}

void addVector2Uniform(const Shader *shader, const char *location, glm::vec2 value) {
    glUniform2f(getUniformLocation(shader, location), value.x, value.y);
}

void addVector3Uniform(const Shader *shader, const char *location, glm::vec3 value) {
    glUniform3f(getUniformLocation(shader, location), value.x, value.y, value.z);
}

void addMatrix4Uniform(const Shader *shader, const char *location, glm::mat4 value) {
    glUniformMatrix4fv(getUniformLocation(shader, location), 1, GL_FALSE, glm::value_ptr(value));
}

void applyTransformMatrix(const Shader *shader, const Transform *transform) {
    glm::mat4 transformMatrix = getTransformMatrix(transform);
    addMatrix4Uniform(shader, "transformMatrix", transformMatrix);
}

#endif //VXL___SHADER_H
