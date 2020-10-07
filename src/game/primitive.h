//
// Created by volko on 07.10.2020.
//

#ifndef VXL___PRIMITIVE_H
#define VXL___PRIMITIVE_H

#include "../d3/MeshData.h"
#include "../d3/Mesh.h"

MeshData createPlainPrimitive(glm::vec3 color) {
    Mesh mesh = Mesh();

    std::vector<glm::vec3> vertices{
            glm::vec3(-0.5, 0, 0.5),
            glm::vec3(0.5, 0, 0.5),
            glm::vec3(-0.5, 0, -0.5),
            glm::vec3(0.5, 0, -0.5)
    };

    std::vector<glm::vec3> normals{
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0)
    };

    std::vector<glm::vec3> colors{
            color,
            color,
            color,
            color
    };

    std::vector<unsigned int> indices{
            0, 2, 1,
            1, 2, 3
    };

    mesh.setVertices(vertices);
    mesh.setNormals(normals);
    mesh.setColors(colors);
    mesh.setIndices(indices);

    return mesh.commit();
}

#endif //VXL___PRIMITIVE_H
