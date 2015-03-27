#ifndef  RO_COLOR_BY_POSITION_H
#define  RO_COLOR_BY_POSITION_H

#include "RenderObject.h"

class RO_ColorByPosition : public RenderObject
{
public:
    RO_ColorByPosition(Model *_model, RenderMethod *_render);
    virtual void Render() override;
};

#endif