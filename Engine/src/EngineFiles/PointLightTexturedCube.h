#ifndef PTL_TEXTURED_CUBE_H
#define PTL_TEXTURED_CUBE_H

#include "Model.h"

class PointLightTexturedCube : public Model
{
public:
    PointLightTexturedCube(const char * const fileName);
    ~PointLightTexturedCube();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif