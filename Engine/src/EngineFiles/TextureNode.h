#ifndef TEXTURE_NODE_H
#define TEXTURE_NODE_H

#include "sb6.h"
#include "node.h"

#define TEXTURE_NAME_SIZE 64

enum class TextureName
{
    UNINITIALIZED,
    BRICK,
    BOHO,
    EYE,
    GHOSTS,
    SCALES,
    SPIRAL
};

class TextureNode : public Node
{
public:
    TextureNode();
    void Set(const char * const _assetName, TextureName _name, GLuint _textureID, GLenum _minFilter, GLenum _magFilter, GLenum _wrapMode);

    char assetName[TEXTURE_NAME_SIZE];
    TextureName name;
    GLuint textureID;
    GLenum minFilter;
    GLenum magFilter;
    GLenum wrapMode;
};


#endif 