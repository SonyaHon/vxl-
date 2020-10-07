//
// Created by Volkov Pavel on 07.10.2020.
//

#include "FreeCameraController.h"
#include <GLFW/glfw3.h>

FreeCameraController::FreeCameraController(Camera *camera, GLFWwindow *window) : camera(camera), window(window) {}

void FreeCameraController::update() {
    // Get mouse coordinates start
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    glm::vec2 mousePos = glm::vec2((float) xpos, (float) ypos);

    mouseLastPos = mouseCurrentPos;
    mouseCurrentPos = mousePos;
    glm::vec2 mouseDelta = (mouseCurrentPos - mouseLastPos) * rotationSpeedCoef;
    // Get mouse coordinates finish

    // rotate self`s camera
    camera->rotate(mouseDelta.y, mouseDelta.x, 0);

    glm::vec3 velocity = glm::vec3(0, 0, 0);
    glm::vec3 direction = camera->getDirection();

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        velocity -= direction;
    } else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        velocity += direction;
    }

    glm::vec3 projectionDirection = glm::normalize(glm::vec3(direction.x, 0, direction.z));
    glm::vec3 perpendicularDirection = glm::cross(projectionDirection, glm::vec3(0, 1, 0));

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        velocity += perpendicularDirection;
    } else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        velocity -= perpendicularDirection;
    }

    float shiftMoveSpeedCoef = 1.0f;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        shiftMoveSpeedCoef = 2.0f;
    }

    camera->translate(velocity * (moveSpeedCoef * shiftMoveSpeedCoef));
}
