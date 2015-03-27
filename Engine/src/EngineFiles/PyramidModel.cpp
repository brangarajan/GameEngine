#include "PyramidModel.h"

//#define PYRAMID_NUM_FACES (sizeof(PyramidIndexList) / sizeof(Face));
//#define PYRAMID_NUM_VERTS (sizeof(PyramidVerts) / sizeof(VertUVN));
//
//Face PyramidIndexList[] = 
//{
//    {0,2,1},
//    {0,3,2},
//    {0,4,3},
//    {0,1,4},
//    {3,4,1},
//    {1,2,3}
//};
//
//VertUVN PyramidVerts[] =
//{
//    // A = 0
//    {0.0f, 0.75f, 0.0f, 0.0f, 0.5f, 0.0f, 0.42f, 0.0f},
//
//    // B = 1
//    {0.0f, 0.0f, -0.5f, 1.0f, 0.0f, 0.0f, 0.29f, -0.32f},
//
//    // C = 2
//    {-0.5f, 0.0f, 0.0f, 1.0f, 1.0f, -0.41f, 0.05f, 0.0f},
//
//    // D = 3
//    {0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.29f, 0.32f},
//
//    // E = 4 
//    {0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.41f, 0.05f, 0.0f},
//};

PyramidModel::PyramidModel(const char * const fileName)
{
    this->CreateVAO(fileName);
    this->name = ModelList::Pyramid;
}

PyramidModel::~PyramidModel()
{
}

void PyramidModel::CreateVAO(const char * const fileName)
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

    //char * vlist = new char[sizeof(VertUVN) * numVertices];
    this->vertexList = new VertUVN[numVertices];
    this->faceList = new Face[numFaces];


    // char *verts = new char[sizeof(VertUVN)* numVertices];

    errorStatus = File::read(handle, vertexList, sizeof(VertUVN) * numVertices);
    assert(errorStatus == FILE_SUCCESS);

    errorStatus = File::read(handle, faceList, sizeof(Face) * numFaces);
    assert(errorStatus == FILE_SUCCESS);



    //// Read from file later
    //fileName;

    //this->numVertices = PYRAMID_NUM_VERTS;
    //this->numFaces = PYRAMID_NUM_FACES;

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

    //GenerateMesh();
}

void PyramidModel::GenerateMesh()
{
    //FileHandle handle;
    //FileError errorStatus;

    //errorStatus = File::open(handle, "PyramidData.bin", FILE_WRITE);
    //assert(errorStatus == FILE_SUCCESS);

    //char n[sizeof(int)];
    //_itoa_s(numVertices, n, sizeof(int), 10);
    //errorStatus = File::write(handle, n, 4);
    //assert(errorStatus == FILE_SUCCESS);

    //char n2[sizeof(int)];
    //_itoa_s(numFaces, n2, sizeof(int), 10);
    //errorStatus = File::write(handle, n2, 4);
    //assert(errorStatus == FILE_SUCCESS);

    //char vlist[sizeof(PyramidVerts)];
    //memcpy(vlist, PyramidVerts, sizeof(VertUVN) * numVertices);
    //errorStatus = File::write(handle, vlist, sizeof(VertUVN) * numVertices);
    //assert(errorStatus == FILE_SUCCESS);

    //char flist[sizeof(PyramidIndexList)];
    //memcpy(flist, PyramidIndexList, sizeof(Face) * numFaces);
    //errorStatus = File::write(handle, flist, sizeof(Face) * numFaces);
    //assert(errorStatus == FILE_SUCCESS);

    //errorStatus = File::close(handle);
    //assert(errorStatus == FILE_SUCCESS);

}