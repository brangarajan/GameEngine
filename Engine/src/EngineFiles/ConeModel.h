#ifndef CONE_MODEL_H
#define CONE_MODEL_H

#include "Model.h"

class ConeModel : public Model
{
public:
    ConeModel(const char * const fileName);
    ~ConeModel();

private:
    void CreateVAO(const char * const fileName) override;
    void GenerateMesh() override;
};

#endif