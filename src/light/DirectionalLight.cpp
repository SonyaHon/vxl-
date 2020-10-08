//
// Created by Volkov Pavel on 08.10.2020.
//

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
