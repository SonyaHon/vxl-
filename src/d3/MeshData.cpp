//
// Created by Volkov Pavel on 07.10.2020.
//

#include "MeshData.h"

MeshData::MeshData(std::vector<float> vertices, std::vector<unsigned int> indices) {
    vaoId = 0;
    glGenVertexArrays(1, &vaoId);
    GLuint indicesVBO, verticesVBO;
    glGenBuffers(1, &indicesVBO);
    usedAttributes = {0};
    vertexCount = indices.size();

    glBindVertexArray(vaoId);

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

    usedVBOs = {indicesVBO, verticesVBO};
}

MeshData::~MeshData() {
    glDeleteBuffers(usedVBOs.size(), usedVBOs.data());
    glDeleteVertexArrays(1, &vaoId);
}

void MeshData::draw() {
    glBindVertexArray(vaoId);
    for (unsigned int usedAttribute : usedAttributes) {
        glEnableVertexAttribArray(usedAttribute);
    }

    glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr);

    for(unsigned int usedAttribute : usedAttributes) {
        glDisableVertexAttribArray(usedAttribute);
    }
    glBindVertexArray(0);
}
