#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "MathEngine.h"
#include "Model.h"
#include "PCSNode.h"
#include "RenderObject.h"

class GameObject : public PCSNode
{
public:
    GameObject(int _ID, RenderObject *gObj, const Vect &_position, const Vect &_scale);
    ~GameObject();

    void Update(float currentTime);
    Matrix &GetWorld();
    RenderObject *GetRenderObject();

    void SetRoll (float _roll);
    void SetPitch (float _pitch);
    void SetYaw (float _yaw);

    int ID;
    Vect position;  //Trans
    Vect scale;     //Scale
    float roll;     //ROTx
    float pitch;    //ROTy
    float yaw;      //ROTz
    float xSpeed;   //XSpeed
    float ySpeed;   //YSpeed
    float zSpeed;   //ZSpeed

private:
    GameObject();
    GameObject(GameObject &rhs);

    Matrix world;
    RenderObject * graphicsObj;

};

#endif