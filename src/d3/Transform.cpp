//
// Created by Volkov Pavel on 07.10.2020.
//

#include "Transform.h"

Transform::Transform() {
    position = glm::vec3(0, 0, 0);
    rotation = glm::vec3(0, 0, 0);
    scale = glm::vec3(1, 1, 1);
}

Transform::Transform(const glm::vec3 &position) : position(position) {
    rotation = glm::vec3(0, 0, 0);
    scale = glm::vec3(1, 1, 1);
}

Transform::Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) : position(position),
                                                                                                     rotation(rotation),
                                                                                                     scale(scale) {}

glm::mat4 Transform::getTransfromationMatrix() {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::translate(mat, position);
    mat = glm::rotate(mat, glm::radians((float) rotation.x), glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, glm::radians((float) rotation.y), glm::vec3(0, 1, 0));
    mat = glm::rotate(mat, glm::radians((float) rotation.z), glm::vec3(0, 0, 1));
    mat = glm::scale(mat, scale);

    return mat;
}
