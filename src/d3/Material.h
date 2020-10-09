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
    Shader *shader;
    Shader *depthShader;
    GLuint texture2d = 0;
    float specularStrength = 0.4;
    float specularSharpness = 2;
    glm::vec3 specularColor = glm::vec3(1, 1, 1);
    bool castsShadows = false;

public:
    void setCastsShadows(bool castsShadows);

    Material(Shader *shader, Shader *depthShader);

    void setSpecularStrength(float specularStrength);

    void setSpecularSharpness(float specularSharpness);

    void setSpecularColor(const glm::vec3 &specularColor);

    void begin();

    void applyCamera(Camera *camera);

    void applyTransform(Transform *transform);

    void applyTransformDirectionalDepth(Transform *transform);

    void end() const;

    static void endDepth() ;

    void applyAmbientLight(AmbientLight *ambientLight);

    void applyDirectionalLight(DirectionalLight *directionalLight);

    [[nodiscard]] bool canCastShadows() const;

    void beginDepth();

    void applyDirectionalLightDepth(DirectionalLight *directionalLight);

    [[nodiscard]] GLuint getTexture2D() const;

    void setTexture2D(GLuint texture2D);
};


#endif //VXL___MATERIAL_H
