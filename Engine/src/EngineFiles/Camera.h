#ifndef CAMERA_H
#define CAMERA_H

#include <math.h>
#include "MathEngine.h"
#include "Node.h"

enum CameraName
{
    CAMERA_0,   // Default
    CAMERA_1,
    CAMERA_2,
    CAMERA_3,
    UNINITIALIZED
};

class Camera : public Node
{
public:
    Camera(CameraName _name);
    void Update(void);
    void SetViewPort(const int _xPos, const int _yPos, const int _width, const int _height);
    void SetPerspective(const float _FOV, const float _AspectRatio, const float _NearZ, const float _FarZ);
    void SetOrientAndPosition(const Vect &up, const Vect &lookat, const Vect &pos);

    // Get/Set
    CameraName GetName() const;
    Matrix &GetPerspective();
    Matrix &GetView();
    Vect &GetPosition(void);
    void SetPostion (const Vect &pos);
    float &GetFOV(void);
    void SetFOV(const float fov);

    // Public data
    CameraName name;
    bool Active;

private:
    // Private helper methods
    void CalculatePlaneDimensions(void);
    void CalculateFrustumVertices(void);
    void CalculateFrustumCollisionNormals(void);
    void UpdateProjection(void);
    void UpdateView(void);

    // Private data
    Matrix projectionMatrix;
    Matrix lookAtMatrix;

    // Camera unit vectors
    Vect Up;
    Vect Direction;
    Vect Right;
    Vect Position;

    // Frustum inputs
    float FOV;
    float AspectRatio;
    float NearZ;
    float FarZ;

    // Screen size
    float NearWidth;
    float NearHeight;
    float FarWidth;
    float FarHeight;

    // Viewports
    int Viewport_X;
    int Viewport_Y;
    int Viewport_W;
    int Viewport_H;

    // World Space coordinates
    Vect NearTopLeft;
    Vect NearTopRight;
    Vect NearBottomLeft;
    Vect NearBottomRight;
    Vect FarTopLeft;
    Vect FarTopRight;
    Vect FarBottomLeft;
    Vect FarBottomRight;

    // Frustum normals
    Vect frontN;
    Vect backN;
    Vect rightN;
    Vect leftN;
    Vect topN;
    Vect bottomN;
};
#endif