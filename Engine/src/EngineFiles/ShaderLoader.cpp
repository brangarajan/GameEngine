#include <assert.h>
#include <sb6.h>
#include "ShaderLoader.h"
#include "File.h"
#include "Game.h"

ShaderLoader::ShaderLoader(ShaderName _name, const char * const baseName) 
    : shaderName(_name)
{
    this->Create(_name, programObject, baseName);
}

void ShaderLoader::Create(ShaderName name, GLuint &programObject, const char * const baseName)
{
    this->shaderName = name;

    char buffer[128];

    // Load vertex shader
    GLuint vs;
    strcpy_s(buffer, 128, baseName);
    strcat_s(buffer, 128, ".vert.glsl");

    Load(vs, buffer, GL_VERTEX_SHADER);

    // Load fragment shader
    GLuint fs;
    strcpy_s(buffer, 128, baseName);
    strcat_s(buffer, 128, ".frag.glsl");

    Load(fs, buffer, GL_FRAGMENT_SHADER);

    programObject = glCreateProgram();

    glAttachShader(programObject, vs);
    glAttachShader(programObject, fs);

    glLinkProgram(programObject);
}

void ShaderLoader::Load(GLuint &shaderObject, const char * const fileName, GLenum shaderType)
{
    FileHandle handle;
    FileError errorStatus;

    //======================================= READ FILE

    // Open the shader file
    errorStatus = File::open(handle, fileName, FileMode::FILE_READ);
    assert( errorStatus == FILE_SUCCESS );

    // Go to the end of file
    errorStatus = File::seek(handle, FileSeek::FILE_SEEK_END, 0);
    assert( errorStatus == FILE_SUCCESS );

    // Determine size of file
    int sizeOfFile;
    errorStatus = File::tell(handle, sizeOfFile);
    assert( errorStatus == FILE_SUCCESS );

    // Return to the start of file
    errorStatus = File::seek(handle, FILE_SEEK_BEGIN, 0);
    assert( errorStatus == FILE_SUCCESS );

    // Tuck away the correct size
    char *data =  new char [sizeOfFile + 1];
    assert( data != 0 );

    // Read the correct number of bytes
    errorStatus = File::read( handle, data, sizeOfFile);
    assert( errorStatus == FILE_SUCCESS );

    // Terminate after
    data[sizeOfFile] = 0;

    // Close the file
    errorStatus = File::close( handle );
    assert( errorStatus == FILE_SUCCESS );

    //======================================= LOAD AND COMPILE SHADER

    // Create a shader object
    shaderObject = glCreateShader(shaderType);
    assert( shaderObject != 0 );

    // Load the shader
    glShaderSource(shaderObject, 1, &data, 0);
    delete [] data;

    // Compile the shader
    glCompileShader(shaderObject);

    // Verify compile worked
    GLint compileStatus = 0;
    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &compileStatus);

    // If compile failed, print error location
    if (!compileStatus)
    {
        char buffer[4096];
        glGetShaderInfoLog(shaderObject, 4096, NULL, buffer);

        printf("Error(ShaderLoader.cpp) %s: %s\n", fileName, buffer);

        glDeleteShader(shaderObject);

        assert(false);
    }
}

void ShaderLoader::SetActive()
{
    glUseProgram(this->programObject);
}

GLuint ShaderLoader::GetLocation(const char * uniformName)
{
    assert (uniformName != 0);
    GLuint location = glGetUniformLocation(this->programObject, uniformName);

    return location;
}
