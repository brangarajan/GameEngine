#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H
#include <stdlib.h>
#include "Model.h"

class CubeModel : public Model
{
public:
    CubeModel(const char * const fileName);
    ~CubeModel();

private:
    void CreateVAO(const char * const fileName) override;
    void GenerateMesh() override;
};

#endif