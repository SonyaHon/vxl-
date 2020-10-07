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
#include <vector>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
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


    FileLoader shaderLoader = FileLoader("res/shaders");
    Shader plainShader = Shader(std::vector<ShaderData>{
            ShaderData{GL_VERTEX_SHADER, shaderLoader.loadFileAsString("plain/vertex.glsl").c_str()},
            ShaderData{GL_FRAGMENT_SHADER, shaderLoader.loadFileAsString("plain/fragment.glsl").c_str()}
    });
    Shader colorShader = Shader(std::vector<ShaderData>{
            ShaderData{GL_VERTEX_SHADER, shaderLoader.loadFileAsString("color/vertex.glsl").c_str()},
            ShaderData{GL_FRAGMENT_SHADER, shaderLoader.loadFileAsString("color/fragment.glsl").c_str()}
    });

    std::vector<float> vertices = {
            0, 0.5, 0,
            -0.5, -0.5, 0,
            0.5, -0.5, 0
    };
    std::vector<unsigned int> indices = {
            0, 1, 2
    };
    MeshData meshData = MeshData(vertices, indices);

    Transform transform = Transform();
    Transform plainTransfrom = Transform();
    plainTransfrom.translateY(-2);

    MeshData plain = createPlainPrimitive(glm::vec3(1, 0.5, 0));

    Camera camera = Camera(45, 1280.0 / 720.0, 0.001, 1000.0);
    camera.translateZ(4);

    FreeCameraController cameraController = FreeCameraController(&camera, window);

    do {
        glClearColor(0.22, 0.22, 0.22, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        transform.rotateY(0.5);

        cameraController.update();

        plainShader.use();
        plainShader.applyTransform(&transform);
        plainShader.applyCamera(&camera);

        meshData.draw();

        Shader::unuse();

        colorShader.use();
        colorShader.applyTransform(&plainTransfrom);
        colorShader.applyCamera(&camera);

        plain.draw();

        Shader::unuse();

        glfwPollEvents();
        glfwSwapBuffers(window);

        unsigned int glError = glGetError();
        if (glError != 0) {
            std::cout << "GL ERROR: " << glError << std::endl;
        }
    } while (!glfwWindowShouldClose(window));

    return 0;
}
