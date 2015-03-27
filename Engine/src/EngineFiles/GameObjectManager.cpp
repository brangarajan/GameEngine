#include "GameObjectManager.h"

void GameObjectManager::Initialize()
{
    GameObjectManager * manager = GetInstance();
    
    manager->tree = new PCSTree();

    PCSNode *rootnode = new PCSNode("GameObjectRoot");

    manager->tree->insert(rootnode, 0);
}

void GameObjectManager::Add(GameObject *_obj)
{
    GameObjectManager * manager = GetInstance();

    GameObject * obj = _obj;

    PCSNode * rootnode = manager->tree->getRoot();

    // Single list
    manager->tree->insert(obj, rootnode);
}

GameObject * GameObjectManager::Find(int _ID)
{
    GameObjectManager * manager = GetInstance();

    PCSNode * rootnode = manager->tree->getRoot();

    GameObject *obj = 0;
    PCSNode *child = rootnode->getChild();

    while (child != 0)
    {
        obj = (GameObject*)child;
        if (obj->ID == _ID)
        {
            break;
        }

        child = child->getSibling();
    }

    return obj;
}

void GameObjectManager::Update(float currentTIme)
{
    GameObjectManager * manager = GetInstance();

    PCSNode * node = manager->tree->getRoot();

    GameObject *obj = 0;
    PCSNode *child = node->getChild();

    while (child != 0)
    {
        obj = (GameObject*)child;
        obj->Update(currentTIme);

        child = child->getSibling();
    }
}

 void GameObjectManager::Draw()
 {
     GameObjectManager * manager = GetInstance();

     PCSNode * node = manager->tree->getRoot();

     GameObject *obj = 0;
     PCSNode *child = node->getChild();
     RenderObject *rObj = 0;
     
     while (child != 0)
     {
         obj = (GameObject*)child;
         rObj = obj->GetRenderObject();
         rObj->Render();

         child = child->getSibling();
     }
 }

GameObjectManager * GameObjectManager::GetInstance()
{
    static GameObjectManager instance;
    return &instance;
}
