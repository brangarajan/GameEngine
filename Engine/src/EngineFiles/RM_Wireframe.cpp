#include "RM_Wireframe.h"
#include "RO_Wireframe.h"
#include "Camera.h"

RM_Wireframe::RM_Wireframe(ShaderLoader * shaderObj)
    : RenderMethod(shaderObj), type (RenderType::Wireframe) { }

void RM_Wireframe::State(RenderObject *gObj)
{
    RO_Wireframe * grObj = (RO_Wireframe *)gObj;
    grObj;
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void RM_Wireframe::Draw(RenderObject *gObj)
{
    RO_Wireframe *grObj = (RO_Wireframe *)gObj;

    glBindVertexArray(grObj->GetModel()->vao);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDisable(GL_CULL_FACE);

    Matrix world = grObj->GetWorld();
    Matrix view = (CameraManager::GetActive())->GetView();
    Matrix t = world * view;

    this->shaderObject->SetActive();
    glUniformMatrix4fv(this->shaderObject->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&(CameraManager::GetActive())->GetPerspective());
    glUniformMatrix4fv(this->shaderObject->GetLocation("mv_matrix"), 1, GL_FALSE, (float *)&t);

    //glDrawArrays(GL_TRIANGLES, 0, (3 * grObj->GetModel()->numVertices));
    glDrawElements(GL_TRIANGLES, (3 * grObj->GetModel()->numFaces), GL_UNSIGNED_INT, 0);

    glEnable(GL_CULL_FACE);    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}