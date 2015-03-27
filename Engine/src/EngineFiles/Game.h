#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include <sb6.h>
#include <math.h>
#include "MathEngine.h"

class Game : public Engine
{
public:
    Game(const char * appName, const int Width, const int Height);

    virtual void Initialize(void);
    virtual void LoadContent(void);
    virtual void Update(float currentTime);
    virtual void Draw(void);
    virtual void UnloadContent(void);
    void OnResize(int w, int h);
    virtual void ClearBuffers();

private:
    Game();

    float           screenWidth;
    float           screenHeight;
    float           aspect;
    Matrix			proj_matrix;
};


#endif