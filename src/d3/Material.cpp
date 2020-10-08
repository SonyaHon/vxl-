//
// Created by Volkov Pavel on 08.10.2020.
//

#include "Material.h"

void Material::begin() {
    shader->use();
}

void Material::applyTransform(Transform *transform) {
    shader->applyTransform(transform);
}

void Material::applyCamera(Camera *camera) {
    shader->applyCamera(camera);
}

void Material::end() {
    Shader::unuse();
}

Material::Material(Shader *shader) : shader(shader) {}

void Material::applyAmbientLight(AmbientLight *ambientLight) {
    shader->applyAmbientLight(ambientLight);
}

void Material::applyDirectionalLight(DirectionalLight *directionalLight) {
    shader->applyDirectionalLight(directionalLight);
}
