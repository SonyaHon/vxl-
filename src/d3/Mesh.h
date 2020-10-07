//
// Created by volko on 07.10.2020.
//

#ifndef VXL___MESH_H
#define VXL___MESH_H

#include <vector>
#include <glm/glm.hpp>
#include "MeshData.h"

class Mesh {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> colors;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;

public:
    void setVertices(std::vector<glm::vec3> vertices);

    void setColors(std::vector<glm::vec3> colors);

    void setNormals(std::vector<glm::vec3> normals);

    void setIndices(std::vector<unsigned int> indices);

    MeshData commit();
};


#endif //VXL___MESH_H
