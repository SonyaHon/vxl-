//
// Created by Volkov Pavel on 08.10.2020.
//

#ifndef VXL___GAMEOBJECT_H
#define VXL___GAMEOBJECT_H


#include "Transform.h"
#include "MeshData.h"
#include "Material.h"
#include "Camera.h"
#include "../light/AmbientLight.h"
#include "../light/DirectionalLight.h"
#include <vector>

class GameObject {
    const char *tag = "";
    Transform *transform;
    MeshData *meshData;
    Material *material;

    std::vector<GameObject *> children;

public:
    GameObject();

    explicit GameObject(const char *tag);

    explicit GameObject(Transform *transform);

    GameObject(const char *tag, Transform *transform);

    void setMeshData(MeshData *meshData);

    void setMaterial(Material *material);

    void addChild(GameObject *gameObject);

    void removeChild(unsigned int index);

    void removeChild(const char *tag);

    void clearChildren();

    void
    render(Camera *camera, AmbientLight *ambientLight, DirectionalLight *directionalLight, Transform *rootTransform);

    void render(Camera *camera, AmbientLight *ambientLight, DirectionalLight *directionalLight);

    [[nodiscard]] const char *getTag() const;

    [[nodiscard]] Transform *getTransform() const;

    [[nodiscard]] Material *getMaterial() const;

    bool hasTag(const char *checkTag);
};


#endif //VXL___GAMEOBJECT_H
