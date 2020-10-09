//
// Created by Volkov Pavel on 08.10.2020.
//

#ifndef VXL___SCENE_H
#define VXL___SCENE_H

#include <vector>
#include "GameObject.h"
#include "Camera.h"
#include "../light/AmbientLight.h"
#include "../light/DirectionalLight.h"
#include "../settings/window-settings.h"

class Scene {
    Camera *mainCamera;
    ViewportSettings *viewportSettings;
    AmbientLight *ambientLight = nullptr;
    DirectionalLight *directionalLight = nullptr;
    std::vector<GameObject *> gameObjects;

    GLuint directionalLightDepthBuffer = 0;
    GLuint directionalLightDepthMap = 0;

public:
    void addGameObject(GameObject *gameObject);

    void removeGameObject(unsigned int index);

    void removeGameObject(const char *tag);

    void clearGameObjects();

    [[nodiscard]] const std::vector<GameObject *> &getGameObjects() const;

    void render();

    void renderDirectionalLightDepthMap();

    Scene(Camera *camera, ViewportSettings *viewportSettings);

    [[nodiscard]] AmbientLight *getAmbientLight() const;

    void setAmbientLight(AmbientLight *ambientLight);

    [[nodiscard]] DirectionalLight *getDirectionalLight() const;

    void setDirectionalLight(DirectionalLight *directionalLight);

    GLuint getDepthTexture() const;
};


#endif //VXL___SCENE_H
