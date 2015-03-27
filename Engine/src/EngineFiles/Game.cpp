#include <sb6.h>
#include <sb6ktx.h>
#include <math.h>
#include "GameIncludes.h"

//-----------------------------------------------------
//  Game::Game()
//      Game Engine constructor
//-----------------------------------------------------
Game::Game(const char * appName, const int Width, const int Height) 
    : Engine (appName, Width, Height), screenWidth((float)Width), screenHeight((float)Height) { }


//-----------------------------------------------------
//  Game::Initialize()
//      Allows the engine to perform any initialization
//      needed before it runs.
//-----------------------------------------------------
void Game::Initialize()
{
    InputManager::Initialize();
    GameObjectManager::Initialize();
}

//-----------------------------------------------------
//  Engine::LoadContent()
//      Allows the user to load all content needed such
//      as graphics, objects, etc.
//-----------------------------------------------------

void Game:: LoadContent()
{
    GameContent::CreateCameras(this->screenWidth, this->screenHeight);

    GameContent::GenerateModels();

    GameContent::LoadGameContent();
}

//-----------------------------------------------------
//  Game::Update()
//      Allows for the user to control process order,
//      AI, Input, Physics, Animation, etc.
//      (Called once per frame.)
//-----------------------------------------------------
void Game::Update(float currentTime) 
{
    Input *in = InputManager::GetInput();

    CameraManager::Update();

    GameObjectManager::Update(currentTime);

    // Camera position update
    Vect v = (CameraManager::GetActive())->GetPosition();

    RO_Texture *texObj = (RO_Texture *)(GameObjectManager::Find(8))->GetRenderObject();
    RO_PtLtTexture *texObjLt = (RO_PtLtTexture *)(GameObjectManager::Find(5))->GetRenderObject();

    if (in->GetKeyState(KEY::KEY_ARROW_UP) == true)
    {
        v[z] -= 0.005f;
        texObj->name = TextureName::GHOSTS;
        texObjLt->textName = TextureName::GHOSTS;
    }

    else if (in->GetKeyState(KEY::KEY_ARROW_DOWN) == true)
    {
        v[z] += 0.005f;
        texObj->name = TextureName::SCALES;
        texObjLt->textName = TextureName::SCALES;
    }

    else if (in->GetKeyState(KEY::KEY_ARROW_RIGHT) == true)
    {
        v[x] += 0.005f;
        texObj->name = TextureName::BOHO;
        texObjLt->textName = TextureName::BOHO;
    }

    else if (in->GetKeyState(KEY::KEY_ARROW_LEFT) == true)
    {
        v[x] -= 0.005f;
        texObj->name = TextureName::SPIRAL;
        texObjLt->textName = TextureName::SPIRAL;
    }

    (CameraManager::GetActive())->SetPostion(v);

    CameraManager::UpdateActiveCamera(in);
    
}

//-----------------------------------------------------
//  Game::Draw()
//      Allows for the graphics to be drawn to the
//      screen.  Use for rendering only.
//      (Called once per frame.)
//-----------------------------------------------------
void Game::Draw()
{
    GameObjectManager::Draw();
}

//-----------------------------------------------------
//  Game::UnloadContent()
//      Unloads all the previously-loaded resources.
//-----------------------------------------------------
void Game::UnloadContent()
{
    //glDeleteVertexArrays(1, &vao);
    //glDeleteProgram(gObj.GetRenderObject()->
    //glDeleteBuffers(1, &vbo);
}

void Game::OnResize(int w, int h)
{
    Engine::OnResize(w, h);
}

void Game::ClearBuffers()
{
    const GLfloat blue[] = { 0.024f, 0.047f, 0.373f, 1.0f };
    const GLfloat one = 1.0f;

    glViewport(0, 0, info.windowWidth, info.windowHeight);
    glClearBufferfv(GL_COLOR, 0, blue);
    glClearBufferfv(GL_DEPTH, 0, &one);
}