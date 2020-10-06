#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "settings/window-settings.h"
#include "shader/Shader.h"
#include "components//MeshData.h"
#include <vector>
#include <filesystem>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // settings
    WindowSettings windowSettings = {1280, 720, "VXL"};
    ViewportSettings viewportSettings = {1280, 720};

    GLFWwindow *window = glfwCreateWindow(windowSettings.width, windowSettings.height, windowSettings.title, nullptr,
                                          nullptr);
    if (window == nullptr) {
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        exit(-1);
    }

    glViewport(0, 0, viewportSettings.width, viewportSettings.height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader = createShader(std::vector<ShaderData>{
            ShaderData{GL_VERTEX_SHADER, std::filesystem::path("plain/vertex.glsl")},
            ShaderData{GL_FRAGMENT_SHADER, std::filesystem::path("plain/fragment.glsl")}
    });

    std::vector<float> vertices = {
            0, 0.5, 0,
            -0.5, -0.5, 0,
            0.5, -0.5, 0
    };
    std::vector<unsigned int> indices = {
            0, 1, 2
    };
    MeshData meshData = createMeshData(vertices, indices);

    Transform transform = getIdentityTransform();

    do {
        glClearColor(0.22, 0.22, 0.22, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);


        useShader(&shader);
        applyTransformMatrix(&shader, &transform);

        drawMeshData(&meshData);

        stopUsingShader();

        glfwPollEvents();
        glfwSwapBuffers(window);

        std::cout << glGetError() << std::endl;
    } while (!glfwWindowShouldClose(window));

    return 0;
}
