#ifndef RO_WIREFRAME_H
#define RO_WIREFRAME_H

#include "RenderObject.h"

class RO_Wireframe : public RenderObject
{
public:
    RO_Wireframe(Model *_model, RenderMethod *_render);
    virtual void Render() override;
};

#endif