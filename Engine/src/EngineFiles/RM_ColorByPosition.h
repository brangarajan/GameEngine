#ifndef RM_COLOR_BY_POSITION_H
#define RM_COLOR_BY_POSITION_H

#include "RenderMethod.h"

class RM_ColorByPosition : public RenderMethod
{
public:
    RM_ColorByPosition(ShaderLoader *shaderObj);

private:
    void State(RenderObject *gObj) override;
    void Draw(RenderObject *gObj) override;
    RenderType type;
};

#endif