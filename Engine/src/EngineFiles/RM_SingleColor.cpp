#include "RM_SingleColor.h"
#include "RO_SingleColor.h"
#include "MathEngine.h"
#include "Camera.h"

RM_SingleColor::RM_SingleColor(ShaderLoader *shaderObj)
    : RenderMethod(shaderObj), type(RenderType::SingleColor) { }

void RM_SingleColor::State(RenderObject *gObj)
{
    RO_SingleColor * grObj = (RO_SingleColor *)gObj;
    grObj;
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void RM_SingleColor::Draw(RenderObject *gObj)
{
    RO_SingleColor *grObj = (RO_SingleColor *)gObj;

    glBindVertexArray(grObj->GetModel()->vao);

    Matrix world = grObj->GetWorld();
    Matrix view = (CameraManager::GetActive())->GetView();
    Matrix t = world * view;

    this->shaderObject->SetActive();
    glUniformMatrix4fv(this->shaderObject->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&(CameraManager::GetActive())->GetPerspective());
    glUniformMatrix4fv(this->shaderObject->GetLocation("mv_matrix"), 1, GL_FALSE, (float *)&t);

    Vect lightColor = grObj->lightColor;
    Vect lightPos = grObj->lightPos;
    //Vect objColor = grObj->objColor;

    glUniform3fv(this->shaderObject->GetLocation("vLightPos"), 1, (float *)&lightPos);
    glUniform4fv(this->shaderObject->GetLocation("vColor"), 1, (float *)&lightColor);
    //glUniform4fv(this->shaderObject->GetLocation("vObjColor"), 1, (float *)&objColor);

    glDrawElements(GL_TRIANGLES, (3 * grObj->GetModel()->numFaces), GL_UNSIGNED_INT, 0);
}

