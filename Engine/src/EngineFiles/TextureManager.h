#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "sb6.h"
#include "TextureNode.h"

class TextureManager
{
public:
    static void Add(const TextureName _name, const char * const _assetName);
    static GLuint Find(const TextureName _name);
    static void DeleteTextures();

private:
    TextureManager();
    static TextureManager * GetInstance();

    void loadTexture(const char * const _assetName, GLuint *&textureID);
    bool loadTGA(const char *_assetname, GLenum _minFilter, GLenum _magFilter, GLenum _wrapMode);
    void addToFront(Node * node, Node * &headPtr);
    GLbyte *readTGABits(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat);

    Node * headPtr;
};

#endif