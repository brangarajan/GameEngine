#ifndef RENDER_METHOD_H
#define RENDER_METHOD_H

#include "ShaderLoader.h"
#include "GameObject.h"
#include "CameraManager.h"

class RenderMethod
{

public:
    RenderMethod (ShaderLoader *shaderObj);
    virtual void State(RenderObject *obj) = 0;
    virtual void Draw(RenderObject *obj) = 0;

    void Process(RenderObject *obj);

    ShaderLoader *shaderObject;
};

enum class RenderType
{
    SingleColor,
    ColorByPosition,
    Wireframe,
    Texture,
    PointLightTexture,
};

#endif