#ifndef NODE_H
#define NODE_H

#include "sb6.h"

class Node
{
public:
    Node() 
    {
        this->Next = 0;
        this->Prev = 0;
    }

    Node *Next;
    Node *Prev;
};

#endif