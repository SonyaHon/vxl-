//
// Created by volko on 07.10.2020.
//

#ifndef VXL___PRIMITIVE_H
#define VXL___PRIMITIVE_H

#include <utility>

#include "../d3/MeshData.h"
#include "../d3/Mesh.h"

MeshData createPlainPrimitive(glm::vec3 color) {
    Mesh mesh = Mesh();

    std::vector<glm::vec3> vertices{
            glm::vec3(-0.5, 0, -0.5),
            glm::vec3(0.5, 0, -0.5),
            glm::vec3(-0.5, 0, 0.5),
            glm::vec3(0.5, 0, 0.5)
    };

    std::vector<glm::vec3> normals{
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0)
    };

    std::vector<glm::vec3> colors{
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color)
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


MeshData createPlainPrimitive(std::vector<glm::vec2> uvs) {
    Mesh mesh = Mesh();

    std::vector<glm::vec3> vertices{
            glm::vec3(-0.5, 0, -0.5),
            glm::vec3(0.5, 0, -0.5),
            glm::vec3(-0.5, 0, 0.5),
            glm::vec3(0.5, 0, 0.5)
    };

    std::vector<glm::vec3> normals{
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0)
    };

    std::vector<unsigned int> indices{
            0, 2, 1,
            1, 2, 3
    };

    mesh.setVertices(vertices);
    mesh.setNormals(normals);
    mesh.setUvs(std::move(uvs));
    mesh.setIndices(indices);

    return mesh.commit();
}

MeshData createCubePrimitive(glm::vec3 color) {
    Mesh mesh = Mesh();

    std::vector<glm::vec3> vertices{
            glm::vec3(-0.5, -0.5, -0.5),
            glm::vec3(0.5, -0.5, -0.5),
            glm::vec3(-0.5, -0.5, 0.5),
            glm::vec3(0.5, -0.5, 0.5),

            glm::vec3(-0.5, -0.5, -0.5),
            glm::vec3(0.5, -0.5, -0.5),
            glm::vec3(-0.5, 0.5, -0.5),
            glm::vec3(0.5, 0.5, -0.5),


            glm::vec3(-0.5, -0.5, 0.5),
            glm::vec3(0.5, -0.5, 0.5),
            glm::vec3(-0.5, 0.5, 0.5),
            glm::vec3(0.5, 0.5, 0.5),


            glm::vec3(-0.5, -0.5, -0.5),
            glm::vec3(-0.5, -0.5, 0.5),
            glm::vec3(-0.5, 0.5, -0.5),
            glm::vec3(-0.5, 0.5, 0.5),


            glm::vec3(0.5, -0.5, -0.5),
            glm::vec3(0.5, -0.5, 0.5),
            glm::vec3(0.5, 0.5, -0.5),
            glm::vec3(0.5, 0.5, 0.5),


            glm::vec3(-0.5, 0.5, -0.5),
            glm::vec3(0.5, 0.5, -0.5),
            glm::vec3(-0.5, 0.5, 0.5),
            glm::vec3(0.5, 0.5, 0.5),
    };
    std::vector<glm::vec3> normals{
            glm::vec3(0, -1, 0),
            glm::vec3(0, -1, 0),
            glm::vec3(0, -1, 0),
            glm::vec3(0, -1, 0),

            glm::vec3(0, 0, -1),
            glm::vec3(0, 0, -1),
            glm::vec3(0, 0, -1),
            glm::vec3(0, 0, -1),

            glm::vec3(0, 0, 1),
            glm::vec3(0, 0, 1),
            glm::vec3(0, 0, 1),
            glm::vec3(0, 0, 1),

            glm::vec3(-1, 0, 0),
            glm::vec3(-1, 0, 0),
            glm::vec3(-1, 0, 0),
            glm::vec3(-1, 0, 0),

            glm::vec3(1, 0, 0),
            glm::vec3(1, 0, 0),
            glm::vec3(1, 0, 0),
            glm::vec3(1, 0, 0),

            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, 1, 0)
    };
    std::vector<glm::vec3> colors{
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),

            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),

            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),

            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),

            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),

            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),
            glm::vec3(color),

    };
    std::vector<unsigned int> indices{
            0, 2, 1, 1, 2, 3,
            4, 6, 5, 5, 6, 7,
            8, 10, 9, 9, 10, 11,
            12, 14, 13, 13, 14, 15,
            16, 18, 17, 17, 18, 19,
            20, 22, 21, 21, 22, 23
    };

    mesh.setVertices(vertices);
    mesh.setNormals(normals);
    mesh.setColors(colors);
    mesh.setIndices(indices);

    return mesh.commit();
}

#endif //VXL___PRIMITIVE_H
