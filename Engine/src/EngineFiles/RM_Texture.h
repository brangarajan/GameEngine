#ifndef RM_TEXTURE_H
#define RM_TEXTURE_H

#include "RenderMethod.h"

class RM_Texture : public RenderMethod
{
public:
    RM_Texture(ShaderLoader * shaderObj);

private:
    void State(RenderObject *gObj) override;
    void Draw(RenderObject *gObj) override;
    RenderType type;
};

#endif