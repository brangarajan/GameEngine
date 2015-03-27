#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sb6.h>
#include "TGATexture.h"
#include "TextureNode.h"
#include "TextureManager.h"


TextureManager::TextureManager() : headPtr(0) { }

// Singleton
TextureManager * TextureManager::GetInstance() 
{
    static TextureManager instance;
    return &instance;
}

// Add a texture
void TextureManager::Add(const TextureName _name, const char * const _assetName)
{
    GLuint textureID;
    GLuint *pID = &textureID;

    TextureManager *manager = TextureManager::GetInstance();

    manager->loadTexture(_assetName, pID);

    TextureNode *node = new TextureNode();

    node->Set(_assetName, _name, textureID, GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);

    manager->addToFront(node, manager->headPtr);
}

// Find a texture
GLuint TextureManager::Find(const TextureName _name)
{
    TextureManager *manager = TextureManager::GetInstance();

    TextureNode * node = (TextureNode *)manager->headPtr;

    while (node != 0)
    {
        if (node->name == _name)
        {
            break;
        }
        node = (TextureNode *)node->Next;
    }

    return node->textureID;
}

// Clear all textures 
void TextureManager::DeleteTextures()
{
    TextureManager *manager = TextureManager::GetInstance();

    TextureNode *node = (TextureNode*)manager->headPtr;

    while (node != 0)
    {
        glDeleteTextures(1, &node->textureID);

        node = (TextureNode *)node->Next;
    }
}

// Add to list
void TextureManager::addToFront(Node * node, Node * &headPtr)
{
    if (headPtr == 0)
    {
        headPtr = node;
        node->Next = 0;
        node->Prev = 0;
    }
    else
    {
        node->Next = headPtr;
        headPtr->Prev = node;
        headPtr = node;
    }
}

void TextureManager::loadTexture(const char * const _assetName, GLuint *&textureID)
{
    // Get an ID for texture
    glGenTextures(1, textureID);

    //Bind the texture
    glBindTexture(GL_TEXTURE_2D, *textureID);

    //Load the textures
    this->loadTGA(_assetName, GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);
}

bool TextureManager::loadTGA(const char *_assetName, GLenum _minFilter, GLenum _magFilter, GLenum _wrapMode)
{
    //bool status = true;
    GLbyte *bits;
    int nWidth, nHeight, nComponents;
    GLenum eFormat;

    // Read the texture bits
    bits = readTGABits(_assetName, &nWidth, &nHeight, &nComponents, &eFormat);
    if(bits == NULL) 
    {
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wrapMode);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _magFilter);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0, eFormat, GL_UNSIGNED_BYTE, bits);

    free(bits);

    if(_minFilter == GL_LINEAR_MIPMAP_LINEAR || 
       _minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       _minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       _minFilter == GL_NEAREST_MIPMAP_NEAREST)
        glGenerateMipmap(GL_TEXTURE_2D);

    return true;
}

GLbyte * TextureManager::readTGABits(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat)
{
    FILE *file;
    
    TGAHEADER tgaheader;

    unsigned long imageSize;
    short sDepth;
    GLbyte *bits = NULL;

    //Default values
    *iWidth = 0;
    *iHeight = 0;
    *eFormat = GL_RGB;
    *iComponents = GL_RGB;

    // Open file
    fopen_s(&file, szFileName, "rb");
    if (file == NULL)
    {
        return NULL;
    }

    // Read in header
    fread(&tgaheader, 18, 1, file);

    *iWidth = tgaheader.width;
    *iHeight = tgaheader.height;
    sDepth = tgaheader.bitsPerPixel/ 8;

    if(tgaheader.bitsPerPixel != 8 && tgaheader.bitsPerPixel != 24 && tgaheader.bitsPerPixel != 32)
    {
        return NULL;
    }

    imageSize = tgaheader.width * tgaheader.height * sDepth;

    bits = (GLbyte *)malloc(imageSize * sizeof(GLbyte));
    if (bits == NULL)
    {
        return NULL;
    }

    if (fread(bits, imageSize, 1, file) != 1)
    {
        free(bits);
        return NULL;
    }

    switch(sDepth)
    {
    case 3:
        *eFormat = GL_BGR;
        *iComponents = GL_RGB;
        break;

    case 4:
        *eFormat = GL_BGRA;
        *iComponents = GL_RGBA;
        break;
    case 1:
        assert( false);
        //  *eFormat = GL_LUMINANCE;
        //  *iComponents = GL_LUMINANCE;
        break;
    default:
        break;
    }

    fclose(file);

    return bits;
}