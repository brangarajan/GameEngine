#include "RO_SingleColor.h"
#include "RenderMethod.h"

RO_SingleColor::RO_SingleColor(Model *_model, RenderMethod *_render, Vect &_lightColor, Vect &_lightPos)
    : RenderObject(_model, _render), lightColor(_lightColor), lightPos(_lightPos) { }

void RO_SingleColor::Render()
{
    this->render->Process(this);
}