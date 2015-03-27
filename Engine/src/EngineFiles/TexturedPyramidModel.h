#ifndef TEXTURED_PYRAMID_MODEL_H
#define TEXTURED_PYRAMID_MODEL_H

#include "Model.h"

class TexturedPyramidModel : public Model
{
public:
    TexturedPyramidModel(const char * const fileName);
    ~TexturedPyramidModel();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif