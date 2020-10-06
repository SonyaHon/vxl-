//
// Created by volko on 07.10.2020.
//

#ifndef VXL___TRANSFORM_H
#define VXL___TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Transform {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};

Transform getIdentityTransform() {
    return Transform {glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)};
}

glm::mat4 getTransformMatrix(const Transform *transform)  {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::translate(mat, transform->position);
    mat = glm::rotate(mat, glm::radians((float) transform->rotation.x), glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, glm::radians((float) transform->rotation.y), glm::vec3(0, 1, 0));
    mat = glm::rotate(mat, glm::radians((float) transform->rotation.z), glm::vec3(0, 0, 1));
    mat = glm::scale(mat, transform->scale);

    return mat;
}

#endif //VXL___TRANSFORM_H
