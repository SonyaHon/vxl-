//
// Created by Volkov Pavel on 07.10.2020.
//

#include "Shader.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(std::vector<ShaderData> shadersData) {
    programId = glCreateProgram();
    shaderIds = std::vector<GLuint>(shadersData.size());


    for (auto &i : shadersData) {
        unsigned int shaderId = glCreateShader(i.type);
        glShaderSource(shaderId, 1, &i.source, nullptr);
        glCompileShader(shaderId);

        int success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
            std::cout << "Shader compiling error\n" << infoLog << std::endl;
            // @TODO add good shader error
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
        std::cout << "Program linking error\n" << infoLog << std::endl;
        exit(-1);
    }

    for (unsigned int shaderId : shaderIds) {
        glDeleteShader(shaderId);
    }
}

Shader::~Shader() {
    glDeleteProgram(programId);
}

void Shader::unuse() {
    glUseProgram(0);
}

void Shader::use() const {
    glUseProgram(programId);
}

GLuint Shader::getUniformLocation(const char *location) {
    return glGetUniformLocation(programId, location);
}

void Shader::applyVec2Uniform(const char *location, glm::vec2 value) {
    glUniform2f(getUniformLocation(location), value.x, value.y);
}

void Shader::applyFloatUniform(const char *location, float value) {
    glUniform1f(getUniformLocation(location), value);
}

void Shader::applyVec3Uniform(const char *location, glm::vec3 value) {
    glUniform3f(getUniformLocation(location), value.x, value.y, value.z);
}

void Shader::applyMat4Uniform(const char *location, glm::mat4 value) {
    glUniformMatrix4fv(getUniformLocation(location), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::applyTransform(const Transform *transform) {
    applyMat4Uniform("transformMatrix", transform->getTransformationMatrix());
}

void Shader::applyCamera(const Camera *camera) {
    applyMat4Uniform("projectionMatrix", camera->getProjectionMatrix());
    applyMat4Uniform("viewMatrix", camera->getViewMatrix());
    applyVec3Uniform("cameraPos", camera->getPosition());
}

void Shader::applyAmbientLight(AmbientLight *ambientLight) {
    applyFloatUniform("ambientStrength", ambientLight->getStrength());
    applyVec3Uniform("ambientColor", ambientLight->getColor());
}

void Shader::applyDirectionalLight(DirectionalLight *directionalLight) {
    applyFloatUniform("directionalStrength", directionalLight->getStrength());
    applyVec3Uniform("directionalDirection", directionalLight->getDirection());
    applyVec3Uniform("directionalColor", directionalLight->getColor());
}

void Shader::applyDirectionalLightDepth(DirectionalLight *directionalLight) {
    applyMat4Uniform("lightSpaceMatrix", directionalLight->getLightSpaceMatrix());
}
