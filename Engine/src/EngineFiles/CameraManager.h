#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Camera.h"
#include "Input.h"

class CameraManager
{
public:
    static void Add(Camera * camera);
    static Camera * Find(CameraName _name);
    static void Update(void);
    static void UpdateActiveCamera(Input * input);
    static void SetActive(Camera * camera);
    static Camera * GetActive(void);

private:
    static CameraManager * GetInstance();
    void AddToList(Node * node, Node * &headPtr);

    Node * headPtr;
    Camera *activeCamera;
};

#endif