//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___TRANSFORM_H
#define VXL___TRANSFORM_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
    glm::vec3 position{};
    glm::vec3 rotation{};
    glm::vec3 scale{};

public:
    Transform();

    Transform(const glm::vec3 &position);

    Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale);

    glm::mat4 getTransfromationMatrix() ;
};


#endif //VXL___TRANSFORM_H
