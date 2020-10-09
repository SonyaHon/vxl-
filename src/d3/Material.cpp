//
// Created by Volkov Pavel on 08.10.2020.
//

#include "Material.h"

void Material::begin() {
    shader->use();
    shader->applyFloatUniform("specularStrength", specularStrength);
    shader->applyFloatUniform("specularSharpness", specularSharpness);
    shader->applyVec3Uniform("specularColor", specularColor);
    if (texture2d != 0) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture2d);
    }
}

void Material::applyTransform(Transform *transform) {
    shader->applyTransform(transform);
}

void Material::applyCamera(Camera *camera) {
    shader->applyCamera(camera);
}

void Material::end() const {
    if (texture2d != 0) {
//        glActiveTexture(GL_NONE);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    Shader::unuse();
}

Material::Material(Shader *shader, Shader *depthShader) : shader(shader), depthShader(depthShader) {}

void Material::applyAmbientLight(AmbientLight *ambientLight) {
    shader->applyAmbientLight(ambientLight);
}

void Material::applyDirectionalLight(DirectionalLight *directionalLight) {
    shader->applyDirectionalLight(directionalLight);
}

void Material::setSpecularStrength(float specularStrength) {
    Material::specularStrength = specularStrength;
}

void Material::setSpecularSharpness(float specularSharpness) {
    Material::specularSharpness = specularSharpness;
}

void Material::setSpecularColor(const glm::vec3 &specularColor) {
    Material::specularColor = specularColor;
}

bool Material::canCastShadows() const {
    return castsShadows;
}

void Material::beginDepth() {
    depthShader->use();
}

void Material::applyDirectionalLightDepth(DirectionalLight *directionalLight) {
    depthShader->applyDirectionalLightDepth(directionalLight);
}

void Material::applyTransformDirectionalDepth(Transform *transform) {
    depthShader->applyTransform(transform);
}

GLuint Material::getTexture2D() const {
    return texture2d;
}

void Material::setTexture2D(GLuint texture2D) {
    texture2d = texture2D;
}

void Material::endDepth() {
    Shader::unuse();
}

void Material::setCastsShadows(bool castsShadows) {
    Material::castsShadows = castsShadows;
}
