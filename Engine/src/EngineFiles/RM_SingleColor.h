#ifndef RM_SINGLE_COLOR_H
#define RM_SINGLE_COLOR_H

#include "RenderMethod.h"

class RM_SingleColor : public RenderMethod
{
public:
    RM_SingleColor(ShaderLoader *shaderObj);

private:
    void State(RenderObject *gObj) override;
    void Draw(RenderObject *gObj) override;
    RenderType type;
};

#endif