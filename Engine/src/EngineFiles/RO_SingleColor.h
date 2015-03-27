#ifndef  RO_SINGLE_COLOR_H
#define  RO_SINGLE_COLOR_H

#include "RenderObject.h"

class RO_SingleColor : public RenderObject
{
public:
    RO_SingleColor(Model *_model, RenderMethod *_render, Vect &_lightColor, Vect &_lightPos);
    virtual void Render() override;
    Vect lightColor;
    Vect lightPos;
};

#endif