#include "BasicCubeModel.h"

#define BCUBE_NUM_VERTS (sizeof(cubeVerts)/ sizeof(Vert));

static Vert cubeVerts[] =
{
    // Triangle 0
    {-0.25f,  0.25f, -0.25f},
    {-0.25f, -0.25f, -0.25f},
    {0.25f, -0.25f, -0.25f},

    // Triangle 1
    {0.25f, -0.25f, -0.25f},
    {0.25f,  0.25f, -0.25f},
    {-0.25f,  0.25f, -0.25f},

    // Triangle 2
    {0.25f, -0.25f, -0.25f},
    {0.25f, -0.25f,  0.25f},
    {0.25f,  0.25f, -0.25f},

    // Triangle 3
    {0.25f, -0.25f,  0.25f},
    {0.25f,  0.25f,  0.25f},
    {0.25f,  0.25f, -0.25f},

    // Triangle 4
    {0.25f, -0.25f,  0.25f},
    {-0.25f, -0.25f,  0.25f},
    {0.25f,  0.25f,  0.25f},

    // Triangle 5
    {-0.25f, -0.25f,  0.25f},
    {-0.25f,  0.25f,  0.25f},
    {0.25f,  0.25f,  0.25f},

    // Triangle 6
    {-0.25f, -0.25f,  0.25f},
    {-0.25f, -0.25f, -0.25f},
    {-0.25f,  0.25f,  0.25f},

    // Triangle 7
    {-0.25f, -0.25f, -0.25f},
    {-0.25f,  0.25f, -0.25f},
    {-0.25f,  0.25f,  0.25f},

    // Triangle 8
    {-0.25f, -0.25f,  0.25f},
    {0.25f, -0.25f,  0.25f},
    {0.25f, -0.25f, -0.25f},

    // Triangle 9
    {0.25f, -0.25f, -0.25f},
    {-0.25f, -0.25f, -0.25f},
    {-0.25f, -0.25f,  0.25f},

    // Triangle 10
    {-0.25f,  0.25f, -0.25f},
    {0.25f,  0.25f, -0.25f},
    {0.25f,  0.25f,  0.25f},

    // Triangle 11
    {0.25f,  0.25f,  0.25f},
    {-0.25f,  0.25f,  0.25f},
    {-0.25f,  0.25f, -0.25f}

};

BasicCubeModel::BasicCubeModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::BasicCube;
}

BasicCubeModel::~BasicCubeModel()
{

}

void BasicCubeModel::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = BCUBE_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vert) * numVertices, cubeVerts, GL_STATIC_DRAW);
    
    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), 0);
    glEnableVertexAttribArray(0);
}