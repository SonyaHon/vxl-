//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___SHADER_H
#define VXL___SHADER_H

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "../d3/Transform.h"
#include "../d3/Camera.h"

struct ShaderData {
    GLenum type;
    const char *source;
};

class Shader {
    GLuint programId;
    std::vector<GLuint> shaderIds;

public:
    Shader(std::vector<ShaderData>);

    ~Shader();

    void use() const;

    static void unuse();

    void applyFloatUniform(const char*, float);

    void applyVec2Uniform(const char*, glm::vec2);

    void applyVec3Uniform(const char*, glm::vec3);

    void applyMat4Uniform(const char*, glm::mat4);

    void applyTransform(const Transform*);

    void applyCamera(const Camera*);

private:
    GLuint getUniformLocation(const char *);
};


#endif //VXL___SHADER_H
