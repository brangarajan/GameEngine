#include "BasicPyramidModel.h"

#define BPYRAMID_NUM_VERTS (sizeof(PyramidVerts)/ sizeof(Vert));

static Vert PyramidVerts[] =
{
    // TRIANGLE ABC
    {0.0f, 0.75f, 0.0f},
    {0.0f, 0.0f, -0.5f},
    {-0.5f, 0.0f, 0.0f},

    // TRIANGLE ACD
    {0.0f, 0.75f, 0.0f},
    {-0.5f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.5f},

    // TRIANGLE EAD
    {0.0f, 0.75f, 0.0f},
    {0.0f, 0.0f, 0.5f},
    {0.5f, 0.0f, 0.0f},

    // TRIANGLE AEB
    {0.0f, 0.75f, 0.0f},
    {0.5f, 0.0f, 0.0f},
    {0.0f, 0.0f, -0.5f},

    // TRIANGLE DBE
    {0.0f, 0.0f, 0.5f},
    {0.0f, 0.0f, -0.5f},
    {0.5f, 0.0f, 0.0f},
    
    // TRIANGLE BDC
    {0.0f, 0.0f, -0.5f},
    {0.0f, 0.0f, 0.5f},
    {-0.5f, 0.0f, 0.0f},

};

BasicPyramidModel::BasicPyramidModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::BasicPyramid;
}

BasicPyramidModel::~BasicPyramidModel()
{

}

void BasicPyramidModel::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = BPYRAMID_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vert) * numVertices, PyramidVerts, GL_STATIC_DRAW);

    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), 0);
    glEnableVertexAttribArray(0);
}