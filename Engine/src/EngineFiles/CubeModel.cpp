#include "CubeModel.h"

//#define CUBE_NUM_FACES (sizeof(CubeIndexList) / sizeof(Face));
//#define CUBE_NUM_VERTS (sizeof(CubeVerts) / sizeof(VertUVN));

//Face CubeIndexList[] = 
//{
//    {0,1,2},
//    {2,3,0},
//    {4,5,6},
//    {5,7,6},
//    {8,9,10},
//    {9,11,10},
//    {12,13,14},
//    {13,15,14},
//    {16,17,18},
//    {18,19,16},
//    {20,21,22},
//    {22,23,20}
//};
//
//VertUVN CubeVerts[] =
//{
//    // 0
//	{-0.25f,  0.25f, -0.25f, 0.0f, 0.0f, -0.6f,  0.6f, -0.6f  },
//    // 1
//	{-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f  },
//    // 3
//	{ 0.25f, -0.25f, -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f  },
//    // 4
//	{ 0.25f,   0.25f, -0.25f, 1.0f, 0.0f,  0.6f,  0.6f, -0.6f  },
//    // 5
//	{ 0.25f, -0.25f, -0.25f, 0.0f, 1.0f, 0.6f, -0.6f, -0.6f  },
//    // 6
//	{ 0.25f, -0.25f,  0.25f, 1.0f, 1.0f, 0.6f, -0.6f,  0.6f  },
//    // 7
//	{ 0.25f,  0.25f, -0.25f, 0.0f, 0.0f, 0.6f,  0.6f, -0.6f  },
//    // 8
//	{ 0.25f,  0.25f,  0.25f, 1.0f, 0.0f, 0.6f,  0.6f,  0.6f  },
//    // 9
//	{ 0.25f, -0.25f,  0.25f, 1.0f, 1.0f,  0.6f, -0.6f, 0.6f  },
//    // 10
//	{-0.25f, -0.25f, 0.25f, 0.0f, 1.0f, -0.6f, -0.6f, 0.6f  },
//    // 11
//	{ 0.25f,  0.25f,  0.25f, 1.0f, 0.0f,  0.6f,  0.6f, 0.6f  },
//    // 12
//	{ -0.25f,  0.25f,  0.25f, 0.0f, 0.0f, -0.6f,  0.6f, 0.6f },
//    // 13
//	{-0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },
//    // 14
//	{-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f },
//    // 15
//	{-0.25f,  0.25f,  0.25f, 1.0f, 0.0f, -0.6f,  0.6f,  0.6f },
//    // 16
//	{-0.25f,  0.25f, -0.25f, 1.0f, 1.0f, -0.6f,  0.6f, -0.6f },
//    // 17
//	{-0.25f, -0.25f,  0.25f, 0.0f, 0.0f, -0.6f, -0.6f,  0.6f },
//    // 18
//	{0.25f, -0.25f,   0.25f, 1.0f, 0.0f,  0.6f, -0.6f,  0.6f },
//    // 19
//	{0.25f, -0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, -0.6f, -0.6f },
//    // 20
//	{-0.25f, -0.25f, -0.25f, 0.0f, 1.0f, -0.6f, -0.6f, -0.6f},
//	// 21
//	{-0.25f,  0.25f, -0.25f, 0.0f, 1.0f, -0.6f, 0.6f, -0.6f }, 
//    // 22
//	{0.25f,  0.25f,  -0.25f, 1.0f, 1.0f,  0.6f, 0.6f, -0.6f }, 
//    // 23
//	{0.25f,  0.25f,   0.25f, 1.0f, 0.0f,  0.6f, 0.6f,  0.6f },
//	// 24
//	{-0.25f,  0.25f,  0.25f, 0.0f, 0.0f, -0.6f, 0.6f,  0.6f },
//};

CubeModel::CubeModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::Cube;
}

CubeModel::~CubeModel()
{
}

void CubeModel::CreateVAO(const char * const fileName)
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
    glGenBuffers(2, &this->vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);

    // Load data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertUVN) * numVertices, this->vertexList, GL_STATIC_DRAW);

    //Define and enable vertex attribute arrays
    void *offsetV = (void *)((unsigned int)&vertexList[0].X - (unsigned int)vertexList);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetV);
    glEnableVertexAttribArray(0);

    void *offsetT = (void *)((unsigned int)&vertexList[0].U - (unsigned int)vertexList);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetT);
    glEnableVertexAttribArray(1);

    void *offsetN = (void*)((unsigned int)&vertexList[0].nX - (unsigned int)vertexList);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertUVN), offsetN);
    glEnableVertexAttribArray(2);


    // Bind 2nd vbo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Face) * this->numFaces, this->faceList, GL_STATIC_DRAW);

    //GenerateMesh();
}

void CubeModel::GenerateMesh()
{
 /*   FileHandle handle;
    FileError errorStatus;

    errorStatus = File::open(handle, "CubeData.bin", FILE_WRITE);
    assert(errorStatus == FILE_SUCCESS);

    char n[sizeof(int)];
    _itoa_s(numVertices, n, sizeof(int), 10);
    errorStatus = File::write(handle, n, 4);
    assert(errorStatus == FILE_SUCCESS);

    char n2[sizeof(int)];
    _itoa_s(numFaces, n2, sizeof(int), 10);
    errorStatus = File::write(handle, n2, 4);
    assert(errorStatus == FILE_SUCCESS);

    char vlist[sizeof(CubeVerts)];
    memcpy(vlist, CubeVerts, sizeof(VertUVN) * numVertices);
    errorStatus = File::write(handle, vlist, sizeof(VertUVN) * numVertices);
    assert(errorStatus == FILE_SUCCESS);

    char flist[sizeof(CubeIndexList)];
    memcpy(flist, CubeIndexList, sizeof(Face) * numFaces);
    errorStatus = File::write(handle, flist, sizeof(Face) * numFaces);
    assert(errorStatus == FILE_SUCCESS);

    errorStatus = File::close(handle);
    assert(errorStatus == FILE_SUCCESS);
    */
}