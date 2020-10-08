#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "settings/window-settings.h"
#include "d3/MeshData.h"
#include "d3/Transform.h"
#include "shader/Shader.h"
#include "utils/FileLoader.h"
#include "game/controllers/FreeCameraController.h"
#include "game/primitive.h"
#include "d3/GameObject.h"
#include <vector>

void framebuffer_size_callback([[maybe_unused]] GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // settings
    WindowSettings windowSettings = {1280, 720, (char *) "VXL"};

    GLFWwindow *window = glfwCreateWindow(windowSettings.width, windowSettings.height, windowSettings.title, nullptr,
                                          nullptr);
    if (window == nullptr) {
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);

    if (glewInit() != GLEW_OK) {
        exit(-1);
    }

    int viewportWidth, viewportHeight;
    glfwGetFramebufferSize(window, &viewportWidth, &viewportHeight);
    ViewportSettings viewportSettings = {viewportWidth, viewportHeight};

    glViewport(0, 0, viewportSettings.width, viewportSettings.height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glEnable(GL_DEPTH_TEST);


    FileLoader shaderLoader = FileLoader("res/shaders");
    Shader plainShader = Shader(std::vector<ShaderData>{
            ShaderData{GL_VERTEX_SHADER, shaderLoader.loadFileAsString("plain/vertex.glsl").c_str()},
            ShaderData{GL_FRAGMENT_SHADER, shaderLoader.loadFileAsString("plain/fragment.glsl").c_str()}
    });
    Shader colorShader = Shader(std::vector<ShaderData>{
            ShaderData{GL_VERTEX_SHADER, shaderLoader.loadFileAsString("color/vertex.glsl").c_str()},
            ShaderData{GL_FRAGMENT_SHADER, shaderLoader.loadFileAsString("color/fragment.glsl").c_str()}
    });



    Camera camera = Camera(45, 1280.0 / 720.0, 0.001, 1000.0);
    camera.translateZ(4);
    FreeCameraController cameraController = FreeCameraController(&camera, window);

    GameObject pl = GameObject("test");
    pl.setMaterial(new Material(&colorShader));
    MeshData meshData = createPlainPrimitive(glm::vec3(1, 1, 1));
    pl.setMeshData(&meshData);

    GameObject child = GameObject("child");
    child.setMaterial(new Material(&colorShader));
    MeshData childMeshData = createPlainPrimitive(glm::vec3(0, 1, 1));
    child.setMeshData(&childMeshData);
    child.getTransform()->translateY(10);
    child.getTransform()->setScaleUniform(0.2);

    pl.addChild(&child);
    pl.getTransform()->setScale(100, 1, 100);
    pl.getTransform()->translateY(-12);

    do {
        glClearColor(0.22, 0.22, 0.22, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cameraController.update();

        child.getTransform()->rotateY(0.2);
        pl.getTransform()->rotateY(0.2);

        pl.render(&camera);

        glfwPollEvents();
        glfwSwapBuffers(window);

        unsigned int glError = glGetError();
        if (glError != 0) {
            std::cout << "GL ERROR: " << glError << std::endl;
        }
    } while (!glfwWindowShouldClose(window));

    return 0;
}
