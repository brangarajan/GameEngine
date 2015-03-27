#include <math.h>
#include "GameObject.h"
#include "MathEngine.h"
#include "RenderObject.h"

GameObject::GameObject(int _ID, RenderObject  *RenderObject, const Vect &_position, const Vect &_scale)
    : PCSNode(), world(IDENTITY), ID(_ID), graphicsObj(RenderObject), position(_position), scale(_scale), 
      roll(0.0f), pitch(0.0f), yaw(0.0f), xSpeed(0.0f), ySpeed(0.0f), zSpeed(0.0f) { }

Matrix & GameObject::GetWorld()
{
    return this->world;
}

RenderObject * GameObject :: GetRenderObject()
{
    return this->graphicsObj;
}

void GameObject::Update(float currentTime)
{
    currentTime;
    Matrix TransA(TRANS, this->position[x], this->position[y], this->position[z]);
    Matrix Scale(SCALE, this->scale[x], this->scale[y], this->scale[z]);

    if (this->roll != 0.0f)
    {
        this->roll += this->xSpeed;
    }

    if (this->pitch != 0.0f)
    {
        this->pitch += this->ySpeed;
    }

    if (this->yaw != 0.0f)
    {
        this->yaw += this->zSpeed;
    }        
    
    Matrix RotX(ROT_X, this->roll);
    Matrix RotY(ROT_Y, this->pitch);
    Matrix RotZ(ROT_Z, this->yaw);

    this->world = Scale * RotX * RotY * RotZ * TransA;
    
    this->graphicsObj->SetWorld(this->world);
}

void GameObject::SetRoll(float _roll)
{
    this->roll = _roll;
}

void GameObject::SetPitch(float _pitch)
{
    this->pitch = _pitch;
}

void GameObject::SetYaw(float _yaw)
{
    this->yaw = _yaw;
}