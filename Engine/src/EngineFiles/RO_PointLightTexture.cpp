#include <assert.h>

#include "RO_PointLightTexture.h"
#include "RenderMethod.h"


RO_PtLtTexture::RO_PtLtTexture(Model *model, RenderMethod *render, TextureName name, Vect &LightColor, Vect &LightPos)
    : RenderObject(model, render), textName(name), lightColor(LightColor), lightPos(LightPos) { }

void RO_PtLtTexture::Render() 
{
    this->render->Process( this );
}