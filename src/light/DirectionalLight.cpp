//
// Created by Volkov Pavel on 08.10.2020.
//

#include <glm/gtc/matrix_transform.hpp>
#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(const glm::vec3 &direction, const glm::vec3 &color, float strength) : direction(
        direction), color(color), strength(strength) {}

const glm::vec3 &DirectionalLight::getDirection() const {
    return direction;
}

void DirectionalLight::setDirection(const glm::vec3 &direction) {
    DirectionalLight::direction = direction;
}

const glm::vec3 &DirectionalLight::getColor() const {
    return color;
}

void DirectionalLight::setColor(const glm::vec3 &color) {
    DirectionalLight::color = color;
}

float DirectionalLight::getStrength() const {
    return strength;
}

void DirectionalLight::setStrength(float strength) {
    DirectionalLight::strength = strength;
}

glm::mat4 DirectionalLight::getLightSpaceMatrix() {
    float nearPlane = 0.01f;
    float farPlane = 1000.0f;

    glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, nearPlane, farPlane);
    glm::mat4 lightView = glm::lookAt(position, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    return lightProjection * lightView;
}
