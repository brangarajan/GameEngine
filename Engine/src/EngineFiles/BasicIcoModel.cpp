#include "BasicIcoModel.h"

#define BICO_NUM_VERTS (sizeof(IcoVerts)/ sizeof(Vert));

static Vert IcoVerts[] =
{
    //// A = 0
    //{-1,  1.62f,  0},
    //// B = 1
    //{1,  1.62f,  0},
    //// C = 2
    //{-1, -1.62f,  0},
    //// D = 3
    //{ 1, -1.62f,  0},
    //// E = 4
    //{ 0, -1,  1.62f},
    //// F = 5
    //{ 0,  1,  1.62f},
    //// G = 6
    //{ 0, -1, -1.62f},
    //// H = 7
    //{ 0,  1, -1.62f},
    //// I = 8
    //{ 1.62f,  0, -1},
    //// J = 9
    //{ 1.62f,  0,  1},
    //// K = 10
    //{-1.62f,  0, -1},
    //// L = 11
    //{-1.62f,  0,  1},

    // TRIANGLE ALF (0/11/5)
    {-1,  1.62f,  0},
    {-1.62f,  0,  1},
    { 0,  1,  1.62f},
    // TRIANGLE AFB (0/5/1)
    {-1,  1.62f,  0},
    { 0,  1,  1.62f},
    {1,  1.62f,  0},
    // TRIANGLE ABH (0/1/7)
    {-1,  1.62f,  0},
    {1,  1.62f,  0},
    { 0,  1, -1.62f},
    // TRIANGLE AHK (0/7/10)
    {-1,  1.62f,  0},
    { 0,  1, -1.62f},
    {-1.62f,  0, -1},
    // TRIANGLE AKL (0/10/11)
    {-1,  1.62f,  0},
    {-1.62f,  0, -1},
    {-1.62f,  0,  1},

    // TRIANGLE BFJ (1/5/9)
    {1,  1.62f,  0},
    { 0,  1,  1.62f},
    { 1.62f,  0,  1},
    // TRIANGLE FLE (5/11/4)
    { 0,  1,  1.62f},
    {-1.62f,  0,  1},
    { 0, -1,  1.62f},
    // TRIANGLE LKC (11/10/2)
    {-1.62f,  0,  1},
    {-1.62f,  0, -1},
    {-1, -1.62f,  0},
    // TRIANGLE KHG (10/7/6)
    {-1.62f,  0, -1},
    { 0,  1, -1.62f},
    { 0, -1, -1.62f},
    // TRIANGLE HBI (7/1/8)
    { 0,  1, -1.62f},
    {1,  1.62f,  0},
    { 1.62f,  0, -1},

    // TRIANGLE DJE (3/9/4)
    { 1, -1.62f,  0},
    { 1.62f,  0,  1},
    { 0, -1,  1.62f},
    // TRIANGLE DEC (3/4/2)
    { 1, -1.62f,  0},
    { 0, -1,  1.62f},
    {-1, -1.62f,  0},
    // TRIANGLE DCG (3/2/6)
    { 1, -1.62f,  0},
    {-1, -1.62f,  0},
    { 0, -1, -1.62f},
    // TRIANGLE DGI (3/6/8)
    { 1, -1.62f,  0},
    { 0, -1, -1.62f},
    { 1.62f,  0, -1},
    // TRIANGLE DIJ (3/8/9)
    { 1, -1.62f,  0},
    { 1.62f,  0, -1},
    { 1.62f,  0,  1},

    // TRIANGLE EJF (4/9/5)
    { 0, -1,  1.62f},
    { 1.62f,  0,  1},
    { 0,  1,  1.62f},
    // TRIANGLE CEL (2/4/11)
    {-1, -1.62f,  0},
    { 0, -1,  1.62f},
    {-1.62f,  0,  1},
    // TRIANGLE GCK (6/2/10)
    { 0, -1, -1.62f},
    {-1, -1.62f,  0},
    {-1.62f,  0, -1},
    // TRIANGLE IGH (8/6/7)
    { 1.62f,  0, -1},
    { 0, -1, -1.62f},
    { 0,  1, -1.62f},
    // TRIANGLE JIB (9/8/1)
    { 1.62f,  0,  1},
    { 1.62f,  0, -1},
    {1,  1.62f,  0},

};

BasicIcoModel::BasicIcoModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::BasicIco;
}

BasicIcoModel::~BasicIcoModel()
{

}

void BasicIcoModel::CreateVAO(const char * const fileName)
{
    // Read from file later
    fileName;

    this->numVertices = BICO_NUM_VERTS;

    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vert) * numVertices, IcoVerts, GL_STATIC_DRAW);

    //Define and enable a vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), 0);
    glEnableVertexAttribArray(0);
}