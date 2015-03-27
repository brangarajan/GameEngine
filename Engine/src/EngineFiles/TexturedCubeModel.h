#ifndef TEXTURED_CUBE_MODEL_H
#define TEXTURED_CUBE_MODEL_H

#include "Model.h"

class TexturedCubeModel : public Model
{
public:
    TexturedCubeModel(const char * const fileName);
    ~TexturedCubeModel();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif