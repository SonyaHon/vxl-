//
// Created by Volkov Pavel on 08.10.2020.
//

#include "GameObject.h"
#include "Camera.h"

GameObject::GameObject() {
    transform = new Transform();
    meshData = nullptr;
    material = nullptr;
}

GameObject::GameObject(const char *tag) : tag(tag) {
    transform = new Transform();
    meshData = nullptr;
    material = nullptr;
}

GameObject::GameObject(Transform *transform) : transform(transform) {
    meshData = nullptr;
    material = nullptr;
}

GameObject::GameObject(const char *tag, Transform *transform) : tag(tag), transform(transform) {
    meshData = nullptr;
    material = nullptr;
}

void GameObject::setMeshData(MeshData *meshData) {
    GameObject::meshData = meshData;
}

void GameObject::setMaterial(Material *material) {
    GameObject::material = material;
}

void GameObject::addChild(GameObject *gameObject) {
    children.push_back(gameObject);
}

void GameObject::removeChild(GameObject *gameObject) {
    for (size_t i = 0; i < children.size(); i++) {
        GameObject *child = children[i];
        if (child != gameObject) continue;

        children.erase(children.begin() + i);
        children.shrink_to_fit();
        break;
    }
}

void GameObject::removeChild(unsigned int index) {
    if (index >= children.size()) return;
    children.erase(children.begin() + index);
    children.shrink_to_fit();
}

void GameObject::removeChild(const char *tag) {
    for (size_t i = 0; i < children.size(); i++) {
        GameObject *child = children[i];
        if (strcmp(child->tag, tag) == 0) continue;

        children.erase(children.begin() + i);
        children.shrink_to_fit();
        break;
    }
}

void GameObject::render(Camera* camera, Transform* rootTransform) {
    if (material != nullptr && meshData != nullptr) {
        // render self
        material->begin();

        Transform resultTransform = rootTransform != nullptr ? (*rootTransform + *transform) : *transform;
        material->applyTransform(&resultTransform);
        material->applyCamera(camera);

        meshData->draw();

        material->end();
    }

    for (GameObject* child : children) {
        child->render(camera, transform);
    }
}

void GameObject::render(Camera* camera) {
    render(camera, nullptr);
}

const char *GameObject::getTag() const {
    return tag;
}

Transform *GameObject::getTransform() const {
    return transform;
}

Material *GameObject::getMaterial() const {
    return material;
}


