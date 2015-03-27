#ifndef ICO_MODEL_H
#define ICO_MODEL_H

#include "Model.h"

class IcoModel : public Model
{
public:
    IcoModel(const char * const fileName);
    ~IcoModel();

private:
    void CreateVAO(const char * const fileName) override;
    void GenerateMesh() override;
};

#endif