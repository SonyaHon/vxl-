//
// Created by Volkov Pavel on 07.10.2020.
//

#include "Camera.h"

Camera::Camera(float fovy, float aspect, float nearPlane, float farPlane) : fovy(fovy), aspect(aspect),
                                                                            nearPlane(nearPlane), farPlane(farPlane) {}

glm::mat4 Camera::getProjectionMatrix() const {
    glm::mat4 mat = glm::perspective(glm::radians(fovy), aspect, nearPlane, farPlane);
    return mat;
}
