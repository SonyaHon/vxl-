//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___CAMERA_H
#define VXL___CAMERA_H


#include "Transform.h"

class Camera : public Transform {
    float fovy;
    float aspect;
    float nearPlane;
    float farPlane;

public:
    Camera(float fovy, float aspect, float nearPlane, float farPlane);

    [[nodiscard]] glm::mat4 getProjectionMatrix() const;
};


#endif //VXL___CAMERA_H
