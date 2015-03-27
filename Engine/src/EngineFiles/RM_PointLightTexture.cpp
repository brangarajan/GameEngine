#include <assert.h>
#include "MathEngine.h"
#include "RO_PointLightTexture.h"
#include "RM_PointLightTexture.h"
#include "TextureManager.h"
#include "CameraManager.h"

RM_PtLtTexture::RM_PtLtTexture(ShaderLoader *shaderObject )
    : RenderMethod(shaderObject), type(RenderType::PointLightTexture) { }

void RM_PtLtTexture::State(RenderObject *p)
{	
    RO_PtLtTexture *pGObj = (RO_PtLtTexture *)p;

    glActiveTexture(GL_TEXTURE0);

    // Bind the texture
    GLuint textureID = TextureManager::Find( pGObj->textName );
    glBindTexture(GL_TEXTURE_2D, textureID);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void RM_PtLtTexture::Draw(RenderObject *p )
{	     
    RO_PtLtTexture *pGObj = (RO_PtLtTexture *)p;
  
    glBindVertexArray(pGObj->GetModel()->vao);

    Matrix world = pGObj->GetWorld();
    Matrix view = CameraManager::GetActive()->GetView();
    Matrix proj = CameraManager::GetActive()->GetPerspective();

    Matrix mv = world * view;

    this->shaderObject->SetActive();

    glUniformMatrix4fv(this->shaderObject->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&proj);
    glUniformMatrix4fv(this->shaderObject->GetLocation("mv_matrix"), 1, GL_FALSE, (float *)&mv);

    Vect lightPos = pGObj->lightPos;
    Vect lightColor = pGObj->lightColor;
    glUniform3fv(this->shaderObject->GetLocation("vLightPos"), 1, (float *)&lightPos);
    glUniform4fv(this->shaderObject->GetLocation("vColor"), 1, (float *)&lightColor);

    //glDrawArrays(GL_TRIANGLES, 0, (3 * pGObj->GetModel()->numVertices));
    glDrawElements(GL_TRIANGLES, (3 * pGObj->GetModel()->numFaces), GL_UNSIGNED_INT, 0);
}


