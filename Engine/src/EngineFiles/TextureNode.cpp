#include <string.h>
#include <sb6.h>
#include "TextureNode.h"

TextureNode::TextureNode()
    : name(TextureName::UNINITIALIZED), textureID(0), minFilter(GL_LINEAR), magFilter(GL_LINEAR), wrapMode(GL_CLAMP_TO_EDGE)
{
    memset(this->assetName, 0, TEXTURE_NAME_SIZE);
}

void TextureNode::Set(const char * const _assetName, TextureName _name, GLuint _textureID, GLenum _minFilter, GLenum _magFilter, GLenum _wrapMode)
{
    memcpy(this->assetName, _assetName, TEXTURE_NAME_SIZE - 1);

    this->name = _name;
    this->textureID = _textureID;
    this->minFilter = _minFilter;
    this->magFilter = _magFilter;
    this->wrapMode = _wrapMode;
}