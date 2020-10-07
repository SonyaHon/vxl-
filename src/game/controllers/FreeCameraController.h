//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___FREECAMERACONTROLLER_H
#define VXL___FREECAMERACONTROLLER_H


#include <GLFW/glfw3.h>
#include "../../d3/Camera.h"

class FreeCameraController {
    Camera *camera;
    GLFWwindow* window;

    glm::vec2 mouseLastPos;
    glm::vec2 mouseCurrentPos;

    float rotationSpeedCoef = 0.2f;
    float moveSpeedCoef = 0.2f;
public:
    FreeCameraController(Camera *camera, GLFWwindow *window);

    void update();
};


#endif //VXL___FREECAMERACONTROLLER_H
