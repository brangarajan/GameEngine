#include "GameContent.h"
#include "GameObjectManager.h"
#include "RO_Includes.h"

GameContent * GameContent::GetInstance()
{
    static GameContent instance;
    return &instance;
}

void GameContent::LoadGameContent()
{
    GameContent *content = GameContent::GetInstance();

    content->AddTextures();
    content->AddShaders();
    content->CreateGameObjects();
}

void GameContent::CreateCameras(float screenWidth, float screenHeight)
{
    Camera * pCam = new Camera(CAMERA_0);
    pCam->SetViewPort(0, 0, (int)screenWidth, (int)screenHeight);
    pCam->SetPerspective(50.0f, (screenWidth/screenHeight), 0.10f, 1000.0f);
    pCam->SetOrientAndPosition( Vect(0.0f,1.0f,0.0f), Vect(0.0f,0.0f,0.0f), Vect(0.0f,0.0f,6.0f) );
    pCam->Active = false;
    CameraManager::Add(pCam);

    pCam = new Camera(CAMERA_1);
    pCam->SetViewPort(0, 0, (int)screenWidth, (int)screenHeight);
    pCam->SetPerspective(50.0f, (screenWidth/screenHeight), 0.10f, 1000.0f);
    pCam->SetOrientAndPosition( Vect(0.0f,1.0f,0.0f), Vect(0.0f,0.0f,0.0f), Vect(0.0f,0.0f,-6.0f) );
    pCam->Active = false;
    CameraManager::Add(pCam);

    pCam = new Camera(CAMERA_2);
    pCam->SetViewPort(0, 0, (int)screenWidth, (int)screenHeight);
    pCam->SetPerspective(50.0f, (screenWidth/screenHeight), 0.10f, 1000.0f);
    pCam->SetOrientAndPosition( Vect(0.0f,1.0f,0.0f), Vect(0.0f,0.0f,2.0f), Vect(0.0f, 7.0f, 7.0f) );
    pCam->Active = true;
    CameraManager::Add(pCam);

    pCam = new Camera(CAMERA_3);
    pCam->SetViewPort(0, 0, (int)screenWidth, (int)screenHeight);
    pCam->SetPerspective(50.0f, (screenWidth/screenHeight), 0.10f, 1000.0f);
    pCam->SetOrientAndPosition( Vect(0.0f,1.0f,0.0f), Vect(0.0f,0.0f,0.0f), Vect(6.0f, 0.0f, 0.0f) );
    pCam->Active = false;
    CameraManager::Add(pCam);

    CameraManager::Update();
}

void GameContent::GenerateModels()
{
    CubeModel *modelC = new CubeModel("../../../MeshData/CubeData.bin");
    PyramidModel *modelP = new PyramidModel("../../../MeshData/PyramidData.bin");
    ConeModel *modelC2 = new ConeModel("../../../MeshData/ConeData.bin");
    IcoModel *modelI = new IcoModel("../../../MeshData/IcoData.bin");

    ModelManager::Add(modelC);
    ModelManager::Add(modelP);
    ModelManager::Add(modelC2);
    ModelManager::Add(modelI);
}

void GameContent::AddTextures()
{
    TextureManager::Add(TextureName::BOHO, "../../../Textures/boho.tga");
    TextureManager::Add(TextureName::EYE, "../../../Textures/eye.tga");
    TextureManager::Add(TextureName::GHOSTS, "../../../Textures/ghosts.tga");
    TextureManager::Add(TextureName::SCALES, "../../../Textures/scales.tga");
    TextureManager::Add(TextureName::SPIRAL, "../../../Textures/spiral.tga");
}

void GameContent::AddShaders()
{   
    ShaderManager::Add(BasicColorShader, "../../../Shaders/SingleColor");
    ShaderManager::Add(ColorByPosShader,"../../../Shaders/ColorByPos");
    ShaderManager::Add(TextureShader, "../../../Shaders/SimpleTexture");
    ShaderManager::Add(PointLightTexShader, "../../../Shaders/PointLightTex");
}

void GameContent::CreateGameObjects()
{
    // Create Render Methods
    RM_ColorByPosition *rmColor = new RM_ColorByPosition(ShaderManager::Find(ShaderName::ColorByPosShader));
    RM_Wireframe *rmWire = new RM_Wireframe(ShaderManager::Find(ShaderName::ColorByPosShader));
    RM_SingleColor *rmsColor = new RM_SingleColor(ShaderManager::Find(ShaderName::BasicColorShader));
    RM_Texture *rmTexture = new RM_Texture(ShaderManager::Find(ShaderName::TextureShader));
    RM_PtLtTexture *rmPtLt = new RM_PtLtTexture(ShaderManager::Find(ShaderName::PointLightTexShader));

    // Create Render Objects

    // 4 Color by position
    RO_ColorByPosition *colorObj = new RO_ColorByPosition(ModelManager::Find(Pyramid), rmColor);
    RO_ColorByPosition *colorObj2 = new RO_ColorByPosition(ModelManager::Find(Icosahedron), rmColor);
    RO_ColorByPosition *colorObj3 = new RO_ColorByPosition(ModelManager::Find(Cone), rmColor);
    RO_ColorByPosition *colorObj4 = new RO_ColorByPosition(ModelManager::Find(Cone), rmColor);
   
    // 4 wireframe
    RO_Wireframe *wireObj = new RO_Wireframe(ModelManager::Find(Icosahedron), rmWire);
    RO_Wireframe *wireObj2 = new RO_Wireframe(ModelManager::Find(Cone), rmWire);
    RO_Wireframe *wireObj3 = new RO_Wireframe(ModelManager::Find(Pyramid), rmWire);
    RO_Wireframe *wireObj4 = new RO_Wireframe(ModelManager::Find(Icosahedron), rmWire);
  
    // 4 single color, single light source
    Vect lightsource(2.0f, 2.0f, 0.0f);
    Vect lightcolor1(1.0f, 0.50f, 0.0f, 1.0f);
    RO_SingleColor *scolorObj = new RO_SingleColor(ModelManager::Find(Pyramid), rmsColor, lightcolor1, lightsource);

    Vect lightcolor2(0.0f, 0.75f, 0.75f, 1.0f);
    RO_SingleColor *scolorObj2 = new RO_SingleColor(ModelManager::Find(Cube), rmsColor, lightcolor2, lightsource);

    Vect lightcolor3(0.75f, 0.0f, 0.75f, 1.0f);
    RO_SingleColor *scolorObj3 = new RO_SingleColor(ModelManager::Find(Cube), rmsColor, lightcolor3, lightsource);

    Vect lightcolor4(0.2f, 0.70f, 0.05f, 1.0f);
    RO_SingleColor *scolorObj4 = new RO_SingleColor(ModelManager::Find(Pyramid), rmsColor, lightcolor4, lightsource);

    // 4 single texture, no light source
    RO_Texture *textureObj = new RO_Texture(ModelManager::Find(Pyramid), rmTexture, TextureName::SPIRAL);
    RO_Texture *textureObj2 = new RO_Texture(ModelManager::Find(Cube), rmTexture, TextureName::EYE);
    RO_Texture *textureObj3 = new RO_Texture(ModelManager::Find(Cone), rmTexture, TextureName::BOHO);
    RO_Texture *textureObj4 = new RO_Texture(ModelManager::Find(Cube), rmTexture, TextureName::GHOSTS);

    // 4 single texture, single light source
    Vect lightcolor(1.5f, 1.5f, 1.5f, 1.0f);
    RO_PtLtTexture *ptlttex1 = new RO_PtLtTexture(ModelManager::Find(Cube), rmPtLt, TextureName::SPIRAL, lightcolor, lightsource);
    RO_PtLtTexture *ptlttex2 = new RO_PtLtTexture(ModelManager::Find(Pyramid), rmPtLt, TextureName::GHOSTS, lightcolor, lightsource);
    RO_PtLtTexture *ptlttex3 = new RO_PtLtTexture(ModelManager::Find(Cube), rmPtLt, TextureName::BOHO, lightcolor, lightsource);
    RO_PtLtTexture *ptlttex4 = new RO_PtLtTexture(ModelManager::Find(Pyramid), rmPtLt, TextureName::SCALES, lightcolor, lightsource);


    // Create Game Objects
    // Middle row
    GameObject * obj = new GameObject(6, colorObj3, Vect(0.0f, -0.25f, 0.0f), Vect(0.75f, 0.75f, 0.75f));
    obj->SetPitch(2.0f);
    obj->ySpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(2, wireObj , Vect (1.5f, 0.0f, 0.0f), Vect(0.2f, 0.2f, 0.2f));
    obj->SetYaw(1.0f);
    obj->zSpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(3, textureObj2, Vect(-1.5f, 0.0f, 0.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetRoll(1.0f);
    obj->xSpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(4, scolorObj , Vect (-3.0f, -0.33f, 0.0f), Vect(0.75f, 1.0f, 0.75f));
    obj->SetPitch(1.0f);
    obj->ySpeed = 0.002f;
    obj->SetYaw(1.0f);
    obj->zSpeed = 0.001f;
    GameObjectManager::Add(obj);

    obj = new GameObject(5, ptlttex3, Vect(3.0f, 0.0f, 0.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetRoll(1.0f);
    obj->SetYaw(1.0f);
    obj->xSpeed = 0.002f;
    obj->zSpeed = 0.002f;
    GameObjectManager::Add(obj);


    // Front row
    obj = new GameObject(1, colorObj, Vect(0.0f, -0.33f, 2.0f), Vect(0.75f, 1.0f, 0.75f));
    obj->SetPitch(2.0f);
    obj->ySpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(7, wireObj2 , Vect(1.5f, -0.25f, 2.0f), Vect(0.75f, 0.75f, 0.75f));
    obj->SetPitch(-1.0f);
    obj->ySpeed = -0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(8, textureObj3, Vect(-1.5f, 0.0f, 2.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetRoll(1.0f);
    obj->xSpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(9, scolorObj2 , Vect (-3.0f, 0.0f, 2.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetYaw(-1.0f);
    obj->zSpeed = -0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(10, ptlttex1, Vect(3.0f, 0.0f, 2.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetPitch(1.0f);
    obj->ySpeed = 0.002f;
    GameObjectManager::Add(obj);


    // Back row
    obj = new GameObject(11, colorObj2, Vect(0.0f, 0.0f, -2.0f), Vect(0.2f, 0.2f, 0.2f));
    obj->SetRoll(1.0f);
    obj->SetPitch(1.0f);
    obj->SetYaw(1.0f);
    obj->xSpeed = 0.002f;
    obj->ySpeed = 0.002f;
    obj->zSpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(12, wireObj3 , Vect (1.5f, -0.33f, -2.0f), Vect(0.75f, 1.0f, 0.75f));
    obj->SetRoll(1.0f);
    obj->xSpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(13, textureObj, Vect(-1.5f, -0.25f, -2.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetPitch(-1.0f);
    obj->ySpeed = -0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(14, scolorObj3 , Vect(-3.0f, -0.25f, -2.0f), Vect(0.75f, 0.75f, 0.75f));
    obj->SetYaw(-1.0f);
    obj->zSpeed = -0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(15, ptlttex2, Vect(3.0f, -0.25f, -2.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetPitch(-1.0f);
    obj->ySpeed = -0.002f;
    GameObjectManager::Add(obj);

    // Even more in front row (?)  I'm le tired.
    obj = new GameObject(16, colorObj4, Vect(0.0f, -0.33f, 4.0f), Vect(0.75f, 0.75f, 0.75f));
    obj->SetRoll(-2.0f);
    obj->xSpeed = -0.002f;
    obj->SetYaw(2.0f);
    obj->zSpeed = 0.004f;
    GameObjectManager::Add(obj);

    obj = new GameObject(17, wireObj4 , Vect(1.5f, 0.0f, 4.0f), Vect(0.2f, 0.2f, 0.2f));
    obj->SetPitch(-1.0f);
    obj->ySpeed = -0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(18, textureObj4, Vect(-1.5f, 0.0f, 4.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetRoll(1.0f);
    obj->xSpeed = 0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(19, scolorObj4 , Vect (-3.0f, 0.0f, 4.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetYaw(-1.0f);
    obj->zSpeed = -0.002f;
    GameObjectManager::Add(obj);

    obj = new GameObject(20, ptlttex4, Vect(3.0f, -0.25f, 4.0f), Vect(1.0f, 1.0f, 1.0f));
    obj->SetPitch(1.0f);
    obj->ySpeed = 0.002f;
    GameObjectManager::Add(obj);

}