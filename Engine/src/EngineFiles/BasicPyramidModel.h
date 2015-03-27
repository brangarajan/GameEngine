#ifndef BASIC_PYRAMID_MODEL_H
#define BASIC_PYRAMID_MODEL_H

#include "Model.h"

class BasicPyramidModel : public Model
{
public:
    BasicPyramidModel(const char * const fileName);
    ~BasicPyramidModel();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif