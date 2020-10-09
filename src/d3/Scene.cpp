//
// Created by Volkov Pavel on 08.10.2020.
//

#include "Scene.h"

const std::vector<GameObject *> &Scene::getGameObjects() const {
    return gameObjects;
}

void Scene::addGameObject(GameObject *gameObject) {
    gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(unsigned int index) {
    if (index >= gameObjects.size()) return;
    gameObjects.erase(gameObjects.begin() + index);
    gameObjects.shrink_to_fit();
}

void Scene::removeGameObject(const char *tag) {
    for (size_t i = 0; i < gameObjects.size(); i++) {
        GameObject *child = gameObjects[i];
        if (child->hasTag(tag)) {
            removeGameObject(i);
            break;
        }
    }
}

void Scene::render() {
    for (auto gameObject : gameObjects) {
        gameObject->render(mainCamera, ambientLight, directionalLight);
    }
}

void Scene::clearGameObjects() {
    gameObjects.clear();
    gameObjects.shrink_to_fit();
}

AmbientLight *Scene::getAmbientLight() const {
    return ambientLight;
}

void Scene::setAmbientLight(AmbientLight *ambientLight) {
    Scene::ambientLight = ambientLight;
}

DirectionalLight *Scene::getDirectionalLight() const {
    return directionalLight;
}

void Scene::setDirectionalLight(DirectionalLight *directionalLight) {
    Scene::directionalLight = directionalLight;
}

void Scene::renderDirectionalLightDepthMap() {
    if (directionalLightDepthBuffer == 0) {
        glGenFramebuffers(1, &directionalLightDepthBuffer);
        glGenTextures(1, &directionalLightDepthMap);
        glBindTexture(GL_TEXTURE_2D, directionalLightDepthMap);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBindFramebuffer(GL_FRAMEBUFFER, directionalLightDepthBuffer);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, directionalLightDepthMap, 0);
        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    glViewport(0, 0, 1024, 1024);
    glBindFramebuffer(GL_FRAMEBUFFER, directionalLightDepthBuffer);
    glClear(GL_DEPTH_BUFFER_BIT);

    for (auto gameObject : gameObjects) {
        gameObject->renderDirectionalLightDepthMap(directionalLight);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, viewportSettings->width, viewportSettings->height);
}

Scene::Scene(Camera* mainCamera, ViewportSettings *viewportSettings) : mainCamera(mainCamera), viewportSettings(viewportSettings) {}

GLuint Scene::getDepthTexture() const {
    return directionalLightDepthMap;
}

