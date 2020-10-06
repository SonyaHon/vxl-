//
// Created by volko on 06.10.2020.
//

#ifndef VXL___MESHDATA_H
#define VXL___MESHDATA_H


#include <GL/glew.h>
#include <vector>

struct MeshData {
    GLuint vaoId;
    unsigned int vertexCount;
    std::vector<unsigned int> usedAttributes;
};

MeshData createMeshData(std::vector<float> vertices, std::vector<unsigned int> indices) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    GLuint indicesVBO, verticesVBO;
    glGenBuffers(1, &indicesVBO);
    std::vector<unsigned int> usedAttributes = {0};

    glBindVertexArray(vao);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &verticesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return MeshData {vao, indices.size(), usedAttributes };
}

void drawMeshData(const MeshData* meshData) {
    glBindVertexArray(meshData->vaoId);
    for (unsigned int usedAttribute : meshData->usedAttributes) {
        glEnableVertexAttribArray(usedAttribute);
    }

    glDrawElements(GL_TRIANGLES, meshData->vertexCount, GL_UNSIGNED_INT, nullptr);

    for(unsigned int usedAttribute : meshData->usedAttributes) {
        glDisableVertexAttribArray(usedAttribute);
    }
    glBindVertexArray(0);
}

#endif //VXL___MESHDATA_H
