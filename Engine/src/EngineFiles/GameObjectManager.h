#ifndef GAME_OBJECT_MANAGER
#define GAME_OBJECT_MANAGER

#include "GameObject.h"
#include "PCSTree.h"


class GameObjectManager
{
public:
    static void Initialize();
    static void Add(GameObject * obj);
    static GameObject * Find(int ID);
    static void Update(float currentTime);
    static void Draw();

private:
    static GameObjectManager * GetInstance();
    PCSTree *tree;
};

#endif