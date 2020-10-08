//
// Created by Volkov Pavel on 08.10.2020.
//

#ifndef VXL___MATERIAL_H
#define VXL___MATERIAL_H


#include "Camera.h"
#include "../shader/Shader.h"

class Material {
    Shader* shader;

public:
    Material(Shader *shader);

    void begin();

    void applyCamera(Camera *camera);

    void applyTransform(Transform *transform);

    void end();
};


#endif //VXL___MATERIAL_H
