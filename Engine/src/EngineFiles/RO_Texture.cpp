#include "RO_Texture.h"
#include "RenderMethod.h"

RO_Texture::RO_Texture(Model *_model, RenderMethod *_render, TextureName _name)
    : RenderObject(_model, _render), name(_name) { }

void RO_Texture::Render()
{
    this->render->Process(this);
}