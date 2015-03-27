#ifndef GAME_CONTENT_H
#define GAME_CONTENT_H

#include "ShaderManager.h"
#include "TextureManager.h"
#include "CameraManager.h"
#include "ModelManager.h"

class GameContent
{
public:
    static void CreateCameras(float screenWidth, float screenHeight);
    static void GenerateModels();
    static void GenerateRenderObjects();
    static void LoadGameContent();

private:
    static GameContent * GetInstance();
    void AddTextures();
    void AddShaders();
    void CreateGameObjects();
};

#endif