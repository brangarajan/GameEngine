#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include "Node.h"
#include "Model.h"
#include "Model_Includes.h"

class ModelManager
{
public:
    static void Add(Model *model);
    static Model * Find(ModelList _name);

private:
    static ModelManager * GetInstance();
    void AddToList(Node * node, Node * &headPtr);

    Node * headPtr;
};
#endif