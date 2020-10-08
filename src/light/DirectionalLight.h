//
// Created by Volkov Pavel on 08.10.2020.
//

#ifndef VXL___DIRECTIONALLIGHT_H
#define VXL___DIRECTIONALLIGHT_H


#include <glm/glm.hpp>

class DirectionalLight {
    glm::vec3 direction;
    glm::vec3 color;
    float strength;

public:
    DirectionalLight(const glm::vec3 &direction, const glm::vec3 &color, float strength);

    [[nodiscard]] const glm::vec3 &getDirection() const;

    void setDirection(const glm::vec3 &direction);

    [[nodiscard]] const glm::vec3 &getColor() const;

    void setColor(const glm::vec3 &color);

    [[nodiscard]] float getStrength() const;

    void setStrength(float strength);
};


#endif //VXL___DIRECTIONALLIGHT_H
