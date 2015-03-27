#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "ShaderLoader.h"

class ShaderManager
{
public:
    static void Add(ShaderName _name, const char * const baseName);
    static ShaderLoader * Find(ShaderName _name);

private:
    static ShaderManager * GetInstance();
    void AddToList(Node * node, Node * &headPtr);

    Node * headPtr;
};

#endif