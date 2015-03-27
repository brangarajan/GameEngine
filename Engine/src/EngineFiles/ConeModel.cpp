#include "ConeModel.h"

//#define CONE_NUM_FACES (sizeof(ConeIndexList) / sizeof(Face));
//#define CONE_NUM_VERTS (sizeof(ConeVerts) / sizeof(VertUVN));
//
//Face ConeIndexList[] = 
//{
//    {0,2,3},
//    {2,1,3},
//    {0,3,4},
//    {3,1,4},
//    {0,4,5},
//    {4,1,5},
//    {0,5,6},
//    {5,1,6},
//    {0,6,7},
//    {6,1,7},
//    {0,7,8},
//    {7,1,8},
//    {0,8,9},
//    {8,1,9},
//    {0,9,2},
//    {9,1,2}
//};
//
//VertUVN ConeVerts[] =
//{
//    // A = 0
//    {0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f},
//    // B = 1
//    {0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f},
//    // C = 2
//    {0.0f, 0.0f, 0.5f, 1.0f, 0.25f, 0.0f, 0.0f, 0.0f},
//    // D = 3
//    {0.353f, 0.0f, 0.353f, 1.0f, 0.75f, 0.0f, 0.0f, 0.0f},
//    // E = 4
//    {0.5f, 0.0f, 0.0f, 1.0f, 0.25f, 0.0f, 0.0f, 0.0f},
//    // F = 5
//    {0.353f, 0.0f, -0.353f,  1.0f, 0.75f, 0.0f, 0.0f, 0.0f},
//    // G = 6
//    {0.0f, 0.0f, -0.5f,  1.0f, 0.25f, 0.0f, 0.0f, 0.0f},
//    // H = 7
//    {-0.353f, 0.0f, -0.353f,  1.0f, 0.75f, 0.0f, 0.0f, 0.0f},
//    // I = 8
//    {-0.5f, 0.0f, 0.0f,  1.0f, 0.25f, 0.0f, 0.0f, 0.0f},
//    // J = 9
//    {-0.353f, 0.0f, 0.353f,  1.0f, 0.75f, 0.0f, 0.0f, 0.0f}
//};

ConeModel::ConeModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::Cone;
}

ConeModel::~ConeModel()
{
}

void ConeModel::CreateVAO(const char * const fileName)
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

void ConeModel::GenerateMesh()
{
  /*  FileHandle handle;
    FileError errorStatus;

    errorStatus = File::open(handle, "ConeData.bin", FILE_WRITE);
    assert(errorStatus == FILE_SUCCESS);

    char n[sizeof(int)];
    _itoa_s(numVertices, n, sizeof(int), 10);
    errorStatus = File::write(handle, n, 4);
    assert(errorStatus == FILE_SUCCESS);

    char n2[sizeof(int)];
    _itoa_s(numFaces, n2, sizeof(int), 10);
    errorStatus = File::write(handle, n2, 4);
    assert(errorStatus == FILE_SUCCESS);

    char vlist[sizeof(ConeVerts)];
    memcpy(vlist, ConeVerts, sizeof(VertUVN) * numVertices);
    errorStatus = File::write(handle, vlist, sizeof(VertUVN) * numVertices);
    assert(errorStatus == FILE_SUCCESS);

    char flist[sizeof(ConeIndexList)];
    memcpy(flist, ConeIndexList, sizeof(Face) * numFaces);
    errorStatus = File::write(handle, flist, sizeof(Face) * numFaces);
    assert(errorStatus == FILE_SUCCESS);

    errorStatus = File::close(handle);
    assert(errorStatus == FILE_SUCCESS);*/

}