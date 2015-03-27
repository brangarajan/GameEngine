#include "RenderMethod.h"


RenderMethod::RenderMethod(ShaderLoader * shaderObj)
    : shaderObject(shaderObj) { }

void RenderMethod::Process(RenderObject *gObj)
{
    this->State(gObj);
    this->Draw(gObj);
}