#include "TexturedPyramidModel.h"

#define TPYRAMID_NUM_VERTS (sizeof(TexturedPyramidVerts)/ sizeof(VertUV));

static VertUV TexturedPyramidVerts[] =
{
    // TRIANGLE ABC
    {0.0f, 0.75f, 0.0f, 0.0f, 0.5f},
    {0.0f, 0.0f, -0.5f, 1.0f, 0.0f},
    {-0.5f, 0.0f, 0.0f, 1.0f, 1.0f},

    // TRIANGLE ACD
    {0.0f, 0.75f, 0.0f, 0.0f, 0.5f},
    {-0.5f, 0.0f, 0.0f,  1.0f, 0.0f},
    {0.0f, 0.0f, 0.5f, 1.0f, 1.0f},

    // TRIANGLE EAD
    {0.0f, 0.75f, 0.0f,  0.0f, 0.5f},
    {0.0f, 0.0f, 0.5f, 1.0f, 0.0f},
    {0.5f, 0.0f, 0.0f, 1.0f, 1.0f},

    // TRIANGLE AEB
    {0.0f, 0.75f, 0.0f, 0.0f, 0.5f},
    {0.5f, 0.0f, 0.0f,  1.0f, 0.0f},
    {0.0f, 0.0f, -0.5f, 1.0f, 1.0f},

    // TRIANGLE DBE
    {0.0f, 0.0f, 0.5f, 1.0f, 1.0f},
    {0.0f, 0.0f, -0.5f, 1.0f, 0.0f},
    {0.5f, 0.0f, 0.0f, 0.0f, 0.5f},

    // TRIANGLE BDC
    {0.0f, 0.0f, -0.5f, 1.0f, 0.0f},
    {0.0f, 0.0f, 0.5f, 1.0f, 1.0f},
    {-0.5f, 0.0f, 0.0f, 0.0f, 0.5f},

};

TexturedPyramidModel::TexturedPyramidModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::TexturedPyramid;
}

TexturedPyramidModel::~TexturedPyramidModel()
{
}

void TexturedPyramidModel::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = TPYRAMID_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertUV) * numVertices, TexturedPyramidVerts, GL_STATIC_DRAW);

    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertUV), 0);
    glEnableVertexAttribArray(0);

    void *offsetT = (void *)((unsigned int)&TexturedPyramidVerts[0].U - (unsigned int)TexturedPyramidVerts);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertUV), offsetT);
    glEnableVertexAttribArray(1);


}