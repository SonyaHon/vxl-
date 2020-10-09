//
// Created by volko on 07.10.2020.
//

#include "Mesh.h"

#include <utility>

void Mesh::setVertices(std::vector<glm::vec3> vertices) {
    Mesh::vertices = std::move(vertices);
}

void Mesh::setColors(std::vector<glm::vec3> colors) {
    useUvs = false;
    Mesh::colors = std::move(colors);
}

void Mesh::setNormals(std::vector<glm::vec3> normals) {
    Mesh::normals = std::move(normals);
}

void Mesh::setIndices(std::vector<unsigned int> indices) {
    Mesh::indices = std::move(indices);
}

MeshData Mesh::commit() {

    std::vector<float> floatVerts;
    for (auto &vec : vertices) {
        floatVerts.push_back(vec.x);
        floatVerts.push_back(vec.y);
        floatVerts.push_back(vec.z);
    }

    std::vector<float> floatNormals;
    for (auto &vec : normals) {
        floatNormals.push_back(vec.x);
        floatNormals.push_back(vec.y);
        floatNormals.push_back(vec.z);
    }


    MeshData meshData = MeshData(floatVerts, indices);
    meshData.addNormals(floatNormals);

    if (useUvs) {
        std::vector<float> floatUvs;
        for (auto &vec : uvs) {
            floatUvs.push_back(vec.x);
            floatUvs.push_back(vec.y);
        }
        meshData.addUvs(floatUvs);
    } else {
        std::vector<float> floatColors;
        for (auto &vec : colors) {
            floatColors.push_back(vec.r);
            floatColors.push_back(vec.g);
            floatColors.push_back(vec.b);
        }
        meshData.addColors(floatColors);
    }

    return meshData;
}

void Mesh::setUvs(std::vector<glm::vec2> uvs) {
    useUvs = true;
    Mesh::uvs = std::move(uvs);
}
