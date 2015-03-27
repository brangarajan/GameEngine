#ifndef RM_WIREFRAME_H
#define RM_WIREFRAME_H

#include "RenderMethod.h"

class RM_Wireframe : public RenderMethod
{
public:
    RM_Wireframe(ShaderLoader * shaderObj);

private:
    void State(RenderObject *gObj) override;
    void Draw(RenderObject *gObj) override;
    RenderType type;
};

#endif