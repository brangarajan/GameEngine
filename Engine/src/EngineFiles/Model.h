#ifndef MODEL_H
#define MODEL_H
#include <assert.h>
#include <stdlib.h>
#include "sb6.h"
#include "MathEngine.h"
#include "Node.h"
#include "ModelList.h"
#include "File.h"

struct VertUVN
{
    float X;
    float Y;
    float Z;
    float U;
    float V;
    float nX;
    float nY;
    float nZ;
};

struct Face
{
    int vA;
    int vB;
    int vC;
};

class Model : public Node
{
public:
    Model();
    virtual ~Model();

    int numVertices;
    int numFaces;
    VertUVN * vertexList;
    Face * faceList;
    GLuint vao;
    GLuint vbo[2];
    ModelList name;

private:
    virtual void CreateVAO(const char * const fileName) = 0;
    virtual void GenerateMesh(void) = 0;

    // Prevent copying
    Model & operator = (Model &model);
};

#endif