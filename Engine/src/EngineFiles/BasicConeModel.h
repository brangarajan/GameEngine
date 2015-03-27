#ifndef BASIC_CONE_MODEL_H
#define BASIC_CONE_MODEL_H

#include "Model.h"

class BasicConeModel : public Model
{
public:
    BasicConeModel(const char * const fileName);
    ~BasicConeModel();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif