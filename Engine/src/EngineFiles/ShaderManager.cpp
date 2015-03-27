#include "ShaderManager.h"

ShaderManager * ShaderManager::GetInstance()
{
    static ShaderManager instance;
    return &instance;
}

void ShaderManager::Add(ShaderName _name, const char * const baseName)
{
    ShaderManager * manager = ShaderManager::GetInstance();

    ShaderLoader *shader = new ShaderLoader(_name, baseName);

    manager->AddToList(shader, manager->headPtr);
}

void ShaderManager::AddToList(Node * node, Node * &headPtr)
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

ShaderLoader * ShaderManager::Find(ShaderName _name)
{
    ShaderManager * manager = ShaderManager::GetInstance();

    Node * node = manager->headPtr;

    while (node != 0)
    {
        if (((ShaderLoader*)node)->shaderName == _name)
        {
            break;
        }

        node = node->Next;
    }

    return (ShaderLoader*)node;
}