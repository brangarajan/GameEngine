#include "Model.h"

Model::Model() : numVertices(0), numFaces(0), vao(0)
{
    this->vbo[0] = 0;
    this->vbo[1] = 0;
}

Model::~Model() { }

