//
// Created by Volkov Pavel on 08.10.2020.
//

#include "GameObject.h"
#include "Camera.h"
#include "../light/AmbientLight.h"

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

void GameObject::removeChild(unsigned int index) {
    if (index >= children.size()) return;
    children.erase(children.begin() + index);
    children.shrink_to_fit();
}

void GameObject::removeChild(const char *tag) {
    for (size_t i = 0; i < children.size(); i++) {
        GameObject *child = children[i];
        if (child->hasTag(tag)) {
            removeChild(i);
            break;
        }
    }
}

void GameObject::render(Camera *camera, AmbientLight *ambientLight, DirectionalLight *directionalLight,
                        Transform *rootTransform) {
    Transform resultTransform = rootTransform != nullptr ? (*rootTransform + *transform) : *transform;
    if (material != nullptr && meshData != nullptr) {
        // render self
        material->begin();

        material->applyTransform(&resultTransform);
        material->applyCamera(camera);
        material->applyAmbientLight(ambientLight);
        material->applyDirectionalLight(directionalLight);

        meshData->draw();

        material->end();
    }

    for (GameObject *child : children) {
        child->render(camera, ambientLight, directionalLight, &resultTransform);
    }
}

void GameObject::render(Camera *camera, AmbientLight *ambientLight, DirectionalLight *directionalLight) {
    render(camera, ambientLight, directionalLight, nullptr);
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

bool GameObject::hasTag(const char *checkTag) {
    return strcmp(tag, checkTag) != 0;
}

void GameObject::clearChildren() {
    children.clear();
    children.shrink_to_fit();
}

void GameObject::renderDirectionalLightDepthMap(DirectionalLight *directionalLight, Transform *rootTransform) {
    Transform resultTransform = rootTransform != nullptr ? (*rootTransform + *transform) : *transform;

    if (material != nullptr && meshData != nullptr && material->canCastShadows()) {
        material->beginDepth();
        material->applyTransformDirectionalDepth(&resultTransform);
        material->applyDirectionalLightDepth(directionalLight);
        meshData->drawDepth();
        Material::endDepth();
    }

    for (auto child: children) {
        child->renderDirectionalLightDepthMap(directionalLight, &resultTransform);
    }
}

void GameObject::renderDirectionalLightDepthMap(DirectionalLight *directionalLight) {
    renderDirectionalLightDepthMap(directionalLight, nullptr);
}


