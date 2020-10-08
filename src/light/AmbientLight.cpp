//
// Created by Volkov Pavel on 08.10.2020.
//

#include "AmbientLight.h"

AmbientLight::AmbientLight(float strength, const glm::vec3 &color) : strength(strength), color(color) {}

float AmbientLight::getStrength() const {
    return strength;
}

void AmbientLight::setStrength(float strength) {
    AmbientLight::strength = strength;
}

const glm::vec3 &AmbientLight::getColor() const {
    return color;
}

void AmbientLight::setColor(const glm::vec3 &color) {
    AmbientLight::color = color;
}
