#ifndef RO_PT_LIGHT_TEXTURE_H
#define RO_PT_LIGHT_TEXTURE_H

#include <sb6.h>
#include "RenderObject.h"
#include "TextureNode.h"

class RO_PtLtTexture :public RenderObject
{
public:
    RO_PtLtTexture(Model *model, RenderMethod *render, TextureName name, Vect &LightColor, Vect &LightPos);
    virtual void Render() override;

    TextureName textName;
    Vect lightColor;
    Vect lightPos;
};
#endif