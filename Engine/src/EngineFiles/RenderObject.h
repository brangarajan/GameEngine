#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include "MathEngine.h"

class Model;
class RenderMethod;

class RenderObject
{
public:
    RenderObject(Model * _model, RenderMethod * _render);
    virtual void Render() = 0;

    Model * GetModel() const;
    RenderMethod * GetRender() const;

    Matrix & GetWorld();
    void SetWorld(Matrix & _world);

protected:
    Model *model;
    RenderMethod *render;
    Matrix world;
};

#endif