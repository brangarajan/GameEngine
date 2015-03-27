#ifndef RO_TEXTURE_H
#define RO_TEXTURE_H

#include "Engine.h"
#include "RenderObject.h"
#include "TextureNode.h"

class RO_Texture : public RenderObject
{
public:
    RO_Texture(Model *_model, RenderMethod *_render, TextureName _tname);
    virtual void Render() override;

    TextureName name;
};

#endif