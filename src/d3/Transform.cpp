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

glm::mat4 Transform::getTransformationMatrix() const {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::translate(mat, position);
    mat = glm::rotate(mat, glm::radians((float) rotation.x), glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, glm::radians((float) rotation.y), glm::vec3(0, 1, 0));
    mat = glm::rotate(mat, glm::radians((float) rotation.z), glm::vec3(0, 0, 1));
    mat = glm::scale(mat, scale);

    return mat;
}

void Transform::rotate(float x, float y, float z) {
    rotation += glm::vec3(x, y, z);
}

void Transform::rotate(glm::vec3 rotationVector) {
    rotation += rotationVector;
}

void Transform::rotateX(float value) {
    rotate(value, 0, 0);
}

void Transform::rotateY(float value) {
    rotate(0, value, 0);
}

void Transform::rotateZ(float value) {
    rotate(0, 0, value);
}

void Transform::setPosition(const glm::vec3 &position) {
    Transform::position = position;
}

glm::mat4 Transform::getViewMatrix() const {
    glm::mat4 mat = glm::mat4(1.0f);
    mat = glm::rotate(mat, glm::radians((float) rotation.x), glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, glm::radians((float) rotation.y), glm::vec3(0, 1, 0));
    mat = glm::rotate(mat, glm::radians((float) rotation.z), glm::vec3(0, 0, 1));
    mat = glm::translate(mat, position * -1.0f);
    return mat;
}

void Transform::translate(glm::vec3 translateVector) {
    position += translateVector;
}

void Transform::translate(float x, float y, float z) {
    position += glm::vec3(x, y, z);
}

void Transform::translateX(float value) {
    translate(value, 0, 0);
}

void Transform::translateY(float value) {
    translate(0, value, 0);
}

void Transform::translateZ(float value) {
    translate(0, 0, value);
}

