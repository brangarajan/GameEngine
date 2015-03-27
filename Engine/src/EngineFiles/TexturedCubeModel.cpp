#include "TexturedCubeModel.h"

#define TCUBE_NUM_VERTS (sizeof(TexturedCubeVerts)/ sizeof(VertUV));

static VertUV TexturedCubeVerts[] =
{
    // Triangle 0
    {-0.25f,  0.25f, -0.25f, 0.0f, 0.0f },
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f },
    {0.25f, -0.25f,  -0.25f, 1.0f, 1.0f },

    // Triangle 1
    {0.25f,  -0.25f, -0.25f, 1.0f, 1.0f },
    {0.25f,   0.25f, -0.25f, 1.0f, 0.0f },
    {-0.25f,  0.25f, -0.25f, 0.0f, 0.0f },

    // Triangle 2
    {0.25f, -0.25f, -0.25f, 0.0f, 1.0f },
    {0.25f, -0.25f,  0.25f, 1.0f, 1.0f },
    {0.25f,  0.25f, -0.25f, 0.0f, 0.0f },

    // Triangle 3
    {0.25f, -0.25f,  0.25f, 1.0f, 1.0f },
    {0.25f,  0.25f,  0.25f, 1.0f, 0.0f },
    {0.25f,  0.25f, -0.25f, 0.0f, 0.0f },

    // Triangle 4
    {0.25f, -0.25f,  0.25f, 1.0f, 1.0f },
    {-0.25f, -0.25f, 0.25f, 0.0f, 1.0f },
    {0.25f,  0.25f,  0.25f, 1.0f, 0.0f },

    // Triangle 5
    {-0.25f, -0.25f,  0.25f, 0.0f, 1.0f },
    {-0.25f,  0.25f,  0.25f, 0.0f, 0.0f },
    {0.25f,   0.25f,  0.25f, 1.0f, 0.0f },

    // Triangle 6
    {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f },
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f },
    {-0.25f,  0.25f,  0.25f, 1.0f, 0.0f },

    // Triangle 7
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f },
    {-0.25f,  0.25f, -0.25f, 1.0f, 1.0f },
    {-0.25f,  0.25f,  0.25f, 1.0f, 0.0f },

    // Triangle 8
    {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f },
    {0.25f, -0.25f,   0.25f, 1.0f, 0.0f },
    {0.25f, -0.25f,  -0.25f, 1.0f, 1.0f },

    // Triangle 9
    {0.25f, -0.25f,  -0.25f, 1.0f, 1.0f},
    {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f},
    {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f},

    // Triangle 10
    {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f },
    {0.25f,  0.25f,  -0.25f, 1.0f, 1.0f },
    {0.25f,  0.25f,   0.25f, 1.0f, 0.0f },

    // Triangle 11
    {0.25f,  0.25f,   0.25f, 1.0f, 0.0f },
    {-0.25f,  0.25f,  0.25f, 0.0f, 0.0f },
    {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f }
};

TexturedCubeModel::TexturedCubeModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::TexturedCube;
}

TexturedCubeModel::~TexturedCubeModel()
{
}

void TexturedCubeModel::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = TCUBE_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertUV) * numVertices, TexturedCubeVerts, GL_STATIC_DRAW);

    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertUV), 0);
    glEnableVertexAttribArray(0);

    void *offsetT = (void *)((unsigned int)&TexturedCubeVerts[0].U - (unsigned int)TexturedCubeVerts);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertUV), offsetT);
    glEnableVertexAttribArray(1);


}