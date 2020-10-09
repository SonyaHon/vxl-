//
// Created by Volkov Pavel on 07.10.2020.
//

#ifndef VXL___MESHDATA_H
#define VXL___MESHDATA_H

#include <GL/glew.h>
#include <vector>

class MeshData {

    GLuint vaoId;
    unsigned int vertexCount{};
    std::vector<unsigned int> usedAttributes;
    std::vector<GLuint> usedVBOs;

public:
    MeshData(std::vector<float> vertices, std::vector<unsigned int> indices);

    ~MeshData();

    void addNormals(std::vector<float>);

    void addColors(std::vector<float>);

    void addUvs(std::vector<float>);

    void draw();

    void drawDepth() const;
};


#endif //VXL___MESHDATA_H
