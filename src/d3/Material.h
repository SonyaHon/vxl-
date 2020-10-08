//
// Created by Volkov Pavel on 08.10.2020.
//

#ifndef VXL___MATERIAL_H
#define VXL___MATERIAL_H


#include "Camera.h"
#include "../shader/Shader.h"
#include "../light/AmbientLight.h"
#include "../light/DirectionalLight.h"

class Material {
    Shader* shader;

public:
    Material(Shader *shader);

    void begin();

    void applyCamera(Camera *camera);

    void applyTransform(Transform *transform);

    void end();

    void applyAmbientLight(AmbientLight *ambientLight);

    void applyDirectionalLight(DirectionalLight *directionalLight);
};


#endif //VXL___MATERIAL_H
