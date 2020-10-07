//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___TRANSFORM_H
#define VXL___TRANSFORM_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {

private:
    glm::vec3 position{};
    glm::vec3 rotation{};
    glm::vec3 scale{};

public:
    Transform();

    Transform(const glm::vec3 &position);

    Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale);

    [[nodiscard]] glm::mat4 getTransformationMatrix() const;

    [[nodiscard]] glm::mat4 getViewMatrix() const;

    void setPosition(const glm::vec3 &position);

    void rotate(float, float, float);

    void rotate(glm::vec3);

    void rotateX(float);

    void rotateY(float);

    void rotateZ(float);

    void translate(float, float, float);

    void translate(glm::vec3);

    void translateX(float);

    void translateY(float);

    void translateZ(float);

    [[nodiscard]] glm::vec3 getDirection() const;
};


#endif //VXL___TRANSFORM_H
