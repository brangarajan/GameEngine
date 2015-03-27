#include "ModelManager.h"

ModelManager * ModelManager::GetInstance()
{
    static ModelManager instance;
    return &instance;
}

void ModelManager::Add(Model * Model)
{
    ModelManager * manager = ModelManager::GetInstance();

    manager->AddToList(Model, manager->headPtr);
}

void ModelManager::AddToList(Node * node, Node * &headPtr)
{
    if (headPtr == 0)
    {
        headPtr = node;
        node->Next = 0;
        node->Prev = 0;
    }
    else
    {
        node->Next = headPtr;
        headPtr->Prev = node;
        headPtr = node;
    }
}

Model * ModelManager::Find(ModelList _name)
{
    ModelManager * manager = ModelManager::GetInstance();

    Model * node = (Model*)manager->headPtr;

    while (node != 0)
    {
        if (node->name == _name)
        {
            break;
        }

        node = (Model*)node->Next;
    }

    return (Model*)node;
}