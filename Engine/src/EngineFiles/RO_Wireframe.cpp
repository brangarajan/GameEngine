#include "RO_Wireframe.h"
#include "RenderMethod.h"

RO_Wireframe::RO_Wireframe(Model *_model, RenderMethod *_render)
    : RenderObject(_model, _render) { }

void RO_Wireframe::Render()
{
    this->render->Process(this);
}