#include "IcoModel.h"
//
//#define ICO_NUM_FACES (sizeof(IcoIndexList) / sizeof(Face));
//#define ICO_NUM_VERTS (sizeof(IcoVerts) / sizeof(VertUVN));

//Face IcoIndexList[] = 
//{
//    {0,11,5},
//    {0,5,1},
//    {0,1,7},
//    {0,7,10},
//    {0,10,11},
//    {1,5,9},
//    {5,11,4},
//    {11,10,2},
//    {10,7,6},
//    {7,1,8},
//    {3,9,4},
//    {3,4,2},
//    {3,2,6},
//    {3,6,8},
//    {3,8,9},
//    {4,9,5},
//    {2,4,11},
//    {6,2,10},
//    {8,6,7},
//    {9,8,1},
//};
//
//VertUVN IcoVerts[] =
//{
//    // A = 0
//    {-1.0f,  1.62f,  0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f},
//    // B = 1
//    {1.0f,  1.62f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
//    // C = 2
//    {-1.0f, -1.62f,  0.0f, 1.0f, 1.1f, 0.0f, 0.0f, 0.0f},
//    // D = 3
//    {1.0f, -1.62f,  0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f},
//    // E = 4
//    {0.0f, -1.0f,  1.62f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
//    // F = 5
//    {0.0f,  1.0f,  1.62f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f},
//    // G = 6
//    {0.0f, -1.0f, -1.62f,  0.0f, 0.5f, 0.0f, 0.0f, 0.0f},
//    // H = 7
//    {0.0f,  1.0f, -1.62f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
//    // I = 8
//    {1.62f,  0.0f, -1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f},
//    // J = 9
//    {1.62f,  0.0f,  1.0f,  0.0f, 0.5f, 0.0f, 0.0f, 0.0f},
//    // K = 10
//    {-1.62f,  0.0f, -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
//    // L = 11
//    {-1.62f, 0.0f, 1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f}
//};

IcoModel::IcoModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::Icosahedron;
}

IcoModel::~IcoModel()
{
}

void IcoModel::CreateVAO(const char * const fileName)
{
    FileHandle handle;
    FileError errorStatus;

    // Open the model file
    errorStatus = File::open(handle, fileName, FileMode::FILE_READ);
    assert(errorStatus == FILE_SUCCESS);

    // Go to the end of file
    errorStatus = File::seek(handle, FileSeek::FILE_SEEK_END, 0);
    assert( errorStatus == FILE_SUCCESS );

    // Determine size of file
    int sizeOfFile;
    errorStatus = File::tell(handle, sizeOfFile);
    assert( errorStatus == FILE_SUCCESS );

    // Return to the start of file
    errorStatus = File::seek(handle, FILE_SEEK_BEGIN, 0);
    assert( errorStatus == FILE_SUCCESS );

    char *vsize = new char[sizeof(int)];

    errorStatus = File::read(handle, vsize, sizeof(int));
    assert(errorStatus == FILE_SUCCESS);

    vsize[2] = 0;
    this->numVertices = atoi(vsize);

    char *fsize = new char[sizeof(int)];
    errorStatus = File::read(handle, fsize, sizeof(int));
    assert(errorStatus == FILE_SUCCESS);

    fsize[2] = 0;
    this->numFaces = atoi(fsize);

    this->vertexList = new VertUVN[numVertices];
    this->faceList = new Face[numFaces];

    errorStatus = File::read(handle, vertexList, sizeof(VertUVN) * numVertices);
    assert(errorStatus == FILE_SUCCESS);

    errorStatus = File::read(handle, faceList, sizeof(Face) * numFaces);
    assert(errorStatus == FILE_SUCCESS);


    // Generate and bind VAO
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // Generate and bind VBO
    glGenBuffers(2  , &this->vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertUVN) * numVertices, this->vertexList, GL_STATIC_DRAW);

    //Define and enable vertex attribute arrays
    void *offsetV = (void *)((unsigned int)&this->vertexList[0].X - (unsigned int)this->vertexList);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetV);
    glEnableVertexAttribArray(0);

    void *offsetT = (void *)((unsigned int)&this->vertexList[0].U - (unsigned int)this->vertexList);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetT);
    glEnableVertexAttribArray(1);

    void *offsetN = (void*)((unsigned int)&this->vertexList[0].nX - (unsigned int)this->vertexList);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetN);
    glEnableVertexAttribArray(2);

    // Bind 2nd vbo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Face) * this->numFaces, this->faceList, GL_STATIC_DRAW);

   // GenerateMesh();
}

void IcoModel::GenerateMesh()
{
   /* FileHandle handle;
    FileError errorStatus;

    errorStatus = File::open(handle, "IcoData.bin", FILE_WRITE);
    assert(errorStatus == FILE_SUCCESS);

    char n[sizeof(int)];
    _itoa_s(numVertices, n, sizeof(int), 10);
    errorStatus = File::write(handle, n, 4);
    assert(errorStatus == FILE_SUCCESS);

    char n2[sizeof(int)];
    _itoa_s(numFaces, n2, sizeof(int), 10);
    errorStatus = File::write(handle, n2, 4);
    assert(errorStatus == FILE_SUCCESS);

    char vlist[sizeof(IcoVerts)];
    memcpy(vlist, IcoVerts, sizeof(VertUVN) * numVertices);
    errorStatus = File::write(handle, vlist, sizeof(VertUVN) * numVertices);
    assert(errorStatus == FILE_SUCCESS);

    char flist[sizeof(IcoIndexList)];
    memcpy(flist, IcoIndexList, sizeof(Face) * numFaces);
    errorStatus = File::write(handle, flist, sizeof(Face) * numFaces);
    assert(errorStatus == FILE_SUCCESS);

    errorStatus = File::close(handle);
    assert(errorStatus == FILE_SUCCESS);
*/
}