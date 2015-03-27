#ifndef BASIC_ICO_MODEL_H
#define BASIC_ICO_MODEL_H

#include "Model.h"

// Icosahedron
class BasicIcoModel : public Model
{
public:
    BasicIcoModel(const char * const fileName);
    ~BasicIcoModel();

private:
    void CreateVAO(const char * const fileName) override;
};

#endif