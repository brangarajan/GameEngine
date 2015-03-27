#include "RenderObject.h"

RenderObject::RenderObject(Model * _model, RenderMethod * _render)
    : model(_model), render(_render), world(IDENTITY) { }

Model *RenderObject::GetModel() const
{
    return this->model;
}

RenderMethod *RenderObject::GetRender() const
{
    return this->render;
}

Matrix &RenderObject::GetWorld() 
{
    return this->world;
}

void RenderObject::SetWorld( Matrix & _world)
{
    this->world = _world;
}
