//
// Created by volko on 07.10.2020.
//

#include "Mesh.h"

#include <utility>

void Mesh::setVertices(std::vector<glm::vec3> vertices) {
    Mesh::vertices = std::move(vertices);
}

void Mesh::setColors(std::vector<glm::vec3> colors) {
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

    std::vector<float> floatColors;
    for (auto &vec : colors) {
        floatColors.push_back(vec.r);
        floatColors.push_back(vec.g);
        floatColors.push_back(vec.b);
    }

    MeshData meshData = MeshData(floatVerts, indices);
    meshData.addNormals(floatNormals);
    meshData.addColors(floatColors);

    return meshData;
}
