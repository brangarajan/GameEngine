#ifndef RM_PT_LT_TEXTURE_H
#define RM_PT_LT_TEXTURE_H

#include "GameObject.h"
#include "RenderMethod.h"
#include "ShaderLoader.h"

class RM_PtLtTexture: public RenderMethod
{
public:
    RM_PtLtTexture(ShaderLoader *shaderObject );

private:
    void State(RenderObject *p) override;
    void Draw(RenderObject *p) override;

    RenderType type;
};

#endif