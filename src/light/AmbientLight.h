//
// Created by Volkov Pavel on 08.10.2020.
//

#ifndef VXL___AMBIENTLIGHT_H
#define VXL___AMBIENTLIGHT_H


#include <glm/glm.hpp>

class AmbientLight {
    float strength;
    glm::vec3 color;
public:
    AmbientLight(float strength, const glm::vec3 &color);

    [[nodiscard]] float getStrength() const;

    void setStrength(float strength);

    [[nodiscard]] const glm::vec3 &getColor() const;

    void setColor(const glm::vec3 &color);
};


#endif //VXL___AMBIENTLIGHT_H
