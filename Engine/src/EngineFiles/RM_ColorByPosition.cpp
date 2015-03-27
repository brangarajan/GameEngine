#include "RM_ColorByPosition.h"
#include "RO_ColorByPosition.h"
#include "MathEngine.h"
#include "Camera.h"

RM_ColorByPosition::RM_ColorByPosition(ShaderLoader *shaderObj)
    : RenderMethod(shaderObj), type(RenderType::ColorByPosition) { }

void RM_ColorByPosition::State(RenderObject *gObj)
{
    RO_ColorByPosition * grObj = (RO_ColorByPosition *)gObj;
    grObj;
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void RM_ColorByPosition::Draw(RenderObject *gObj)
{
    RO_ColorByPosition *grObj = (RO_ColorByPosition *)gObj;

    glBindVertexArray(grObj->GetModel()->vao);
    
    Matrix world = grObj->GetWorld();
    Matrix view = (CameraManager::GetActive())->GetView();
    Matrix t = world * view;

    this->shaderObject->SetActive();
    glUniformMatrix4fv(this->shaderObject->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&(CameraManager::GetActive())->GetPerspective());
    glUniformMatrix4fv(this->shaderObject->GetLocation("mv_matrix"), 1, GL_FALSE, (float *)&t);

    glDrawElements(GL_TRIANGLES, 3 * grObj->GetModel()->numFaces, GL_UNSIGNED_INT, 0);
}

