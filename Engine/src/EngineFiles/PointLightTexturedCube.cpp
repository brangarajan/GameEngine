#include "PointLightTexturedCube.h"

#define PTLCUBE_NUM_VERTS (sizeof(PLTexturedCubeVerts)/ sizeof(VertUVN));

static VertUVN PLTexturedCubeVerts[] =
{
    // Triangle 0
    {-0.25f,  0.25f, -0.25f, 0.0f, 0.0f, -0.6f,  0.6f, -0.6f  },
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f  },
    {0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f,  -0.6f, -0.6f  },

    // Triangle 1
    {0.25f,  -0.25f, -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f  },
    {0.25f,   0.25f, -0.25f, 1.0f, 0.0f,  0.6f,  0.6f, -0.6f  },
    {-0.25f,  0.25f, -0.25f, 0.0f, 0.0f, -0.6f,  0.6f, -0.6f  },

    // Triangle 2
    {0.25f, -0.25f, -0.25f, 0.0f, 1.0f, 0.6f, -0.6f, -0.6f  },
    {0.25f, -0.25f,  0.25f, 1.0f, 1.0f, 0.6f, -0.6f,  0.6f  },
    {0.25f,  0.25f, -0.25f, 0.0f, 0.0f, 0.6f,  0.6f, -0.6f  },

    // Triangle 3
    {0.25f, -0.25f,  0.25f, 1.0f, 1.0f, 0.6f, -0.6f,  0.6f  },
    {0.25f,  0.25f,  0.25f, 1.0f, 0.0f, 0.6f,  0.6f,  0.6f  },
    {0.25f,  0.25f, -0.25f, 0.0f, 0.0f, 0.6f,  0.6f, -0.6f  },

    // Triangle 4
    {0.25f, -0.25f,  0.25f, 1.0f, 1.0f,  0.6f, -0.6f, 0.6f  },
    {-0.25f, -0.25f, 0.25f, 0.0f, 1.0f, -0.6f, -0.6f, 0.6f  },
    {0.25f,  0.25f,  0.25f, 1.0f, 0.0f,  0.6f,  0.6f, 0.6f  },

    // Triangle 5
    {-0.25f, -0.25f,  0.25f, 0.0f, 1.0f, -0.6f, -0.6f, 0.6f },
    {-0.25f,  0.25f,  0.25f, 0.0f, 0.0f, -0.6f,  0.6f, 0.6f },
    {0.25f,   0.25f,  0.25f, 1.0f, 0.0f,  0.6f,  0.6f, 0.6f },

    // Triangle 6
    {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
    {-0.25f,  0.25f,  0.25f, 1.0f, 0.0f, -0.6f,  0.6f,  0.6f },

    // Triangle 7
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
    {-0.25f,  0.25f, -0.25f, 1.0f, 1.0f, -0.6f,  0.6f, -0.6f },
    {-0.25f,  0.25f,  0.25f, 1.0f, 0.0f, -0.6f,  0.6f,  0.6f },

    // Triangle 8
    {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },
    {0.25f, -0.25f,   0.25f, 1.0f, 0.0f,  0.6f, -0.6f,  0.6f },
    {0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f },

    // Triangle 9
    {0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f},
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f},
    {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f},

    // Triangle 10
    {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f, -0.6f, 0.6f, -0.6f },
    {0.25f,  0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, 0.6f, -0.6f },
    {0.25f,  0.25f,   0.25f, 1.0f, 0.0f,  0.6f, 0.6f,  0.6f },

    // Triangle 11
    {0.25f,  0.25f,   0.25f, 1.0f, 0.0f,  0.6f, 0.6f,  0.6f },
    {-0.25f,  0.25f,  0.25f, 0.0f, 0.0f, -0.6f, 0.6f,  0.6f },
    {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f, -0.6f, 0.6f, -0.6f }
};

PointLightTexturedCube::PointLightTexturedCube(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::PtLightTexCube;
}

PointLightTexturedCube::~PointLightTexturedCube()
{
}

void PointLightTexturedCube::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = PTLCUBE_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertUVN) * numVertices, PLTexturedCubeVerts, GL_STATIC_DRAW);

    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertUVN), 0);
    glEnableVertexAttribArray(0);

    void *offsetT = (void *)((unsigned int)&PLTexturedCubeVerts[0].U - (unsigned int)PLTexturedCubeVerts);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetT);
    glEnableVertexAttribArray(1);

    void *offsetN = (void*)((unsigned int)&PLTexturedCubeVerts[0].nX - (unsigned int)PLTexturedCubeVerts);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetN);
    glEnableVertexAttribArray(2);
}