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

Scene::Scene(Camera *camera) {
    mainCamera = camera;
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

