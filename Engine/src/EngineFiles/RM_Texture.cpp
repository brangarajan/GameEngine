#include "RM_Texture.h"
#include "RO_Texture.h"
#include "TextureManager.h"
#include "Camera.h"

RM_Texture::RM_Texture(ShaderLoader * shaderObj)
    : RenderMethod(shaderObj), type (RenderType::Texture) { }

void RM_Texture::State(RenderObject *gObj)
{
    RO_Texture * grObj = (RO_Texture *)gObj;

    glActiveTexture(GL_TEXTURE0);

    GLuint textureID = TextureManager::Find(grObj->name);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void RM_Texture::Draw(RenderObject *gObj)
{
    RO_Texture *grObj = (RO_Texture *)gObj;

    glBindVertexArray(grObj->GetModel()->vao);

    Matrix world = grObj->GetWorld();
    Matrix view = (CameraManager::GetActive())->GetView();
    Matrix t = world * view;

    this->shaderObject->SetActive();
    glUniformMatrix4fv(this->shaderObject->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&(CameraManager::GetActive())->GetPerspective());
    glUniformMatrix4fv(this->shaderObject->GetLocation("mv_matrix"), 1, GL_FALSE, (float *)&t);

    //glDrawArrays(GL_TRIANGLES, 0, (3 * grObj->GetModel()->numVertices));
    glDrawElements(GL_TRIANGLES, (3 * grObj->GetModel()->numFaces), GL_UNSIGNED_INT, 0);
}