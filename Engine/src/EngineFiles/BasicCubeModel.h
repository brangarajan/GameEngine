#ifndef BASIC_CUBE_MODEL_H
#define BASIC_CUBE_MODEL_H

#include "Model.h"

class BasicCubeModel : public Model
{
public:
    BasicCubeModel(const char * const fileName);
    ~BasicCubeModel();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif