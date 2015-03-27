#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include "sb6.h"
#include "Node.h"

enum ShaderName
{
    BasicColorShader,
    ColorByPosShader,
    TextureShader,
    PointLightTexShader,
};

class ShaderLoader : public Node
{
public:
    ShaderLoader(ShaderName name, const char * const baseName);
    void Create(ShaderName name, GLuint &programObject, const char * const baseName);
    void Load(GLuint &shaderObject, const char * const fileName, GLenum shaderType);
    void SetActive();
    GLuint GetLocation(const char * uniformName);

    ShaderName shaderName;
    GLuint  programObject;
};

#endif