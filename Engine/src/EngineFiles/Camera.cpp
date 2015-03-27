#include "Camera.h"
#include "sb6.h"

Camera::Camera(CameraName _name) : name(_name) { }

void Camera::Update()
{
    // Update the dimensions
    this->CalculatePlaneDimensions();

    // Calculate the frustum verts
    this->CalculateFrustumVertices();

    // Calculate the frustum collision normals
    this->CalculateFrustumCollisionNormals();

    // Update projection matrix
    this->UpdateProjection();

    // Update view matrix
    this->UpdateView();
}

// Camera setup functions
void Camera::SetPerspective(const float _FOV, const float _AspectRatio, const float _NearZ, const float _FarZ)
{
    this->FOV = _FOV;
    this->AspectRatio = _AspectRatio;
    this->NearZ = _NearZ;
    this->FarZ = _FarZ;
}

void Camera::SetViewPort(const int _xPos, const int _yPos, const int _width, const int _height)
{
    this->Viewport_X = _xPos;
    this->Viewport_Y = _yPos;
    this->Viewport_W = _width;
    this->Viewport_H = _height;

    glViewport(this->Viewport_X, this->Viewport_Y, this->Viewport_W, this->Viewport_H);
}

void Camera::SetOrientAndPosition(const Vect &up, const Vect &lookat, const Vect &pos)
{
    this->Direction = pos - lookat;
    this->Direction.norm();

    this->Right = up.cross(this->Direction);
    this->Right.norm();

    this->Up = this->Direction.cross(this->Right);
    this->Up.norm();

    this->Position = pos;
}


// Private update functions

void Camera::CalculatePlaneDimensions()
{
    this->NearHeight = 2.0f * tanf(( this->FOV * MATH_PI/180.0f ) * 0.5f) * this->NearZ;
    this->NearWidth = this->NearHeight * this->AspectRatio;

    this->FarHeight = 2.0f * tanf(( this->FOV * MATH_PI/180.0f) * 0.5f) * this->FarZ;
    this->FarWidth = this->FarHeight * this->AspectRatio;
}

void Camera::CalculateFrustumVertices()
{
    this->NearTopLeft		= this->Position - this->Direction * this->NearZ + this->Up * this->NearHeight * 0.5f - this->Right * this->NearWidth * 0.5f;
    this->NearTopRight		= this->Position - this->Direction * this->NearZ + this->Up * this->NearHeight * 0.5f + this->Right * this->NearWidth * 0.5f;
    this->NearBottomLeft	= this->Position - this->Direction * this->NearZ - this->Up * this->NearHeight * 0.5f - this->Right * this->NearWidth * 0.5f;
    this->NearBottomRight	= this->Position - this->Direction * this->NearZ - this->Up * this->NearHeight * 0.5f + this->Right * this->NearWidth * 0.5f;
    this->FarTopLeft		= this->Position - this->Direction * this->FarZ  + this->Up * this->FarHeight * 0.5f  - this->Right * this->FarWidth * 0.5f;
    this->FarTopRight		= this->Position - this->Direction * this->FarZ  + this->Up * this->FarHeight * 0.5f  + this->Right * this->FarWidth * 0.5f;
    this->FarBottomLeft		= this->Position - this->Direction * this->FarZ  - this->Up * this->FarHeight * 0.5f  - this->Right * this->FarWidth * 0.5f;
    this->FarBottomRight   	= this->Position - this->Direction * this->FarZ  - this->Up * this->FarHeight * 0.5f  + this->Right * this->FarWidth * 0.5f;
}

void Camera::CalculateFrustumCollisionNormals()
{
    Vect A, B, C;

    // Around NearTopLeft
    A = this->NearBottomLeft - this->NearTopLeft;
    B = this->NearTopRight - this->NearTopLeft;
    C = this->FarTopLeft - this->NearTopLeft;

    this->frontN = A.cross(B);
    this->frontN.norm();

    this->leftN = C.cross(A);
    this->leftN.norm();

    this->topN = B.cross(C);
    this->topN.norm();

    // Around FarBottomRight
    A = this->FarBottomLeft - this->FarBottomRight;
    B = this->FarTopRight - this->FarBottomRight;
    C = this->NearBottomRight - this->FarBottomRight;

    this->backN = A.cross(B);
    this->backN.norm();

    this->rightN = B.cross(C);
    this->rightN.norm();

    this->bottomN = C.cross(A);
    this->bottomN.norm();
}

void Camera::UpdateProjection()
{
    this->projectionMatrix[m0] = 2.0f * this->NearZ / this->NearWidth;
    this->projectionMatrix[m1] = 0.0f;
    this->projectionMatrix[m2] = 0.0f;
    this->projectionMatrix[m3] = 0.0f;

    this->projectionMatrix[m4] = 0.0f;    
    this->projectionMatrix[m5] = 2.0f * this->NearZ / this->NearHeight; 
    this->projectionMatrix[m6] = 0.0f;    
    this->projectionMatrix[m7] = 0.0f;

    this->projectionMatrix[m8] = 0.0f;  
    this->projectionMatrix[m9] = 0.0f;  
    this->projectionMatrix[m10] = (this->NearZ + this->FarZ) / (this->NearZ - this->FarZ);   
    this->projectionMatrix[m11] = -1.0f;

    this->projectionMatrix[m12] = 0.0f;
    this->projectionMatrix[m13] = 0.0f;    
    this->projectionMatrix[m14] = (2.0f * this->NearZ * this->FarZ) / (this->NearZ - this->FarZ);
    this->projectionMatrix[m15] = 0.0f;
}

void Camera::UpdateView()
{
    this->lookAtMatrix[m0] = this->Right[x];
    this->lookAtMatrix[m1] = this->Up[x];
    this->lookAtMatrix[m2] = this->Direction[x];
    this->lookAtMatrix[m3] = 0.0f;

    this->lookAtMatrix[m4] = this->Right[y];
    this->lookAtMatrix[m5] = this->Up[y];
    this->lookAtMatrix[m6] = this->Direction[y];
    this->lookAtMatrix[m7] = 0.0f;

    this->lookAtMatrix[m8]  = this->Right[z];
    this->lookAtMatrix[m9]  = this->Up[z];
    this->lookAtMatrix[m10] = this->Direction[z];
    this->lookAtMatrix[m11] = 0.0f;

    this->lookAtMatrix[m12] = -Position.dot(Right);
    this->lookAtMatrix[m13] = -Position.dot(Up);
    this->lookAtMatrix[m14] = -Position.dot(Direction);
    this->lookAtMatrix[m15] = 1.0f;    
}


// Misc Get/Set
CameraName Camera::GetName() const
{
    return this->name;
}

Matrix &Camera::GetPerspective()
{
    return this->projectionMatrix;
}

Matrix &Camera::GetView()
{
    return this->lookAtMatrix;
}

Vect &Camera::GetPosition()
{
    return this->Position;
}

void Camera::SetPostion(const Vect &pos)
{
    this->Position = pos;
}

float &Camera::GetFOV()
{
    return this->FOV;
}

void Camera::SetFOV(const float fov)
{
    this->FOV = fov;
}