#ifndef PYRAMID_MODEL_H
#define PYRAMID_MODEL_H

#include "Model.h"

class PyramidModel : public Model
{
public:
    PyramidModel(const char * const fileName);
    ~PyramidModel();

private:
    void CreateVAO(const char * const fileName) override;
    void GenerateMesh() override;
};

#endif