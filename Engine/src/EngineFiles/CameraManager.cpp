#include "CameraManager.h"

CameraManager * CameraManager::GetInstance()
{
    static CameraManager instance;
    return &instance;
}

void CameraManager::Add(Camera * camera)
{
    CameraManager * manager = CameraManager::GetInstance();

    manager->AddToList(camera, manager->headPtr);

    if (camera->Active == true)
    {
        manager->SetActive(camera);
    }
}

void CameraManager::AddToList(Node * node, Node * &headPtr)
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

Camera * CameraManager::Find(CameraName _name)
{
    CameraManager * manager = CameraManager::GetInstance();

    Node * node = manager->headPtr;

    while (node != 0)
    {
        if (((Camera*)node)->Active == true && ((Camera*)node) != manager->activeCamera)
        {
            ((Camera*)node)->Active = false;
        }

        if (((Camera*)node)->name == _name)
        {
            break;
        }

        node = node->Next;
    }

    return (Camera*)node;
}

void CameraManager::Update()
{
    CameraManager * manager = CameraManager::GetInstance();

    Node * node = manager->headPtr;
    Camera * obj = 0;

    while (node != 0)
    {
        obj = (Camera *)node;
       
        obj->Update();

        node = node->Next;
    }
}

void CameraManager::UpdateActiveCamera(Input * input)
{
    // Active camera update
    if (input->GetKeyState(KEY::KEY_1) == true)
    {
        CameraManager::SetActive(CameraManager::Find(CAMERA_0));
    }

    else if (input->GetKeyState(KEY::KEY_2) == true)
    {
        CameraManager::SetActive(CameraManager::Find(CAMERA_1));
    }

    else if (input->GetKeyState(KEY::KEY_3) == true)
    {
        CameraManager::SetActive(CameraManager::Find(CAMERA_2));
    }

    else if (input->GetKeyState(KEY::KEY_4) == true)
    {
        CameraManager::SetActive(CameraManager::Find(CAMERA_3));
    }
}

void CameraManager::SetActive(Camera * camera)
{
    CameraManager * manager = CameraManager::GetInstance();
    manager->activeCamera = camera;
}

Camera * CameraManager::GetActive()
{
    CameraManager * manager = CameraManager::GetInstance();
    return manager->activeCamera;
}