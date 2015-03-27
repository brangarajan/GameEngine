#include "BasicConeModel.h"

#define BCONE_NUM_VERTS (sizeof(ConeVerts)/ sizeof(Vert));

static Vert ConeVerts[] =
{
    // A
    //{0.0f, 1.0f, 0.0f}
    // B
    //{0.0f, 0.0f, 0.0f}
    // C
    // {0.0f, 0.0f, 0.5f}
    // D
    // {0.353f, 0.0f, 0.353f}
    // E
    //{0.5f, 0.0f, 0.0f}
    // F
    //{0.353f, 0.0f, -0.353f}
    // G
    //{0.0f, 0.0f, -0.5f}
    // H
    //{-0.353f, 0.0f, -0.353f}
    // I
    //{-0.5f, 0.0f, 0.0f}
    // J
    //{-0.353f, 0.0f, 0.353f}


    // ACD
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 0.5f},
    {0.353f, 0.0f, 0.353f},

    // CBD
    {0.0f, 0.0f, 0.5f},
    {0.0f, 0.0f, 0.0f},
    {0.353f, 0.0f, 0.353f},

    // ADE
    {0.0f, 1.0f, 0.0f},
    {0.353f, 0.0f, 0.353f},
    {0.5f, 0.0f, 0.0f},

    // DBE
    {0.353f, 0.0f, 0.353f},
    {0.0f, 0.0f, 0.0f},
    {0.5f, 0.0f, 0.0f},

    // AEF
    {0.0f, 1.0f, 0.0f},
    {0.5f, 0.0f, 0.0f},
    {0.353f, 0.0f, -0.353f},

    // EBF
    {0.5f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f},
    {0.353f, 0.0f, -0.353f},

    // AFG
    {0.0f, 1.0f, 0.0f},
    {0.353f, 0.0f, -0.353f},
    {0.0f, 0.0f, -0.5f},

    // FBG
    {0.353f, 0.0f, -0.353f},
    {0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, -0.5f},

    // AGH
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, -0.5f},
    {-0.353f, 0.0f, -0.353f},

    // GBH
    {0.0f, 0.0f, -0.5f},
    {0.0f, 0.0f, 0.0f},
    {-0.353f, 0.0f, -0.353f},

    // AHI
    {0.0f, 1.0f, 0.0f},
    {-0.353f, 0.0f, -0.353f},
    {-0.5f, 0.0f, 0.0f},

    // HBI
    {-0.353f, 0.0f, -0.353f},
    {0.0f, 0.0f, 0.0f},
    {-0.5f, 0.0f, 0.0f},

    // AIJ
    {0.0f, 1.0f, 0.0f},
    {-0.5f, 0.0f, 0.0f},
    {-0.353f, 0.0f, 0.353f},

    // IBJ
    {-0.5f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f},
    {-0.353f, 0.0f, 0.353f},

    // AJC
    {0.0f, 1.0f, 0.0f},
    {-0.353f, 0.0f, 0.353f},
    {0.0f, 0.0f, 0.5f},

    // JBC
    {-0.353f, 0.0f, 0.353f},
    {0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.5f},



};

BasicConeModel::BasicConeModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::BasicCone;
}

BasicConeModel::~BasicConeModel()
{

}

void BasicConeModel::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = BCONE_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vert) * numVertices, ConeVerts, GL_STATIC_DRAW);

    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), 0);
    glEnableVertexAttribArray(0);
}