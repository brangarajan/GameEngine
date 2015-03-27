#include "RO_ColorByPosition.h"
#include "RenderMethod.h"

RO_ColorByPosition::RO_ColorByPosition(Model *_model, RenderMethod *_render)
    : RenderObject(_model, _render) { }

void RO_ColorByPosition::Render()
{
    this->render->Process(this);
}