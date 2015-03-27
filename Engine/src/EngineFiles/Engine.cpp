
#include "Engine.h"
#include <GL/glext.h>
#include <string.h>

Engine * Engine::app = 0;

// Private default c'tor, use specialized instead!
Engine::Engine() 
{
    strcpy_s(info.title, "Game Engine Demo");
    info.windowWidth = 800;
    info.windowHeight = 600;

    info.majorVersion = 4;
    info.minorVersion = 0;

    info.samples = 0;
    info.flags.all = 0;
    info.flags.cursor = 1;
#ifdef _DEBUG
    info.flags.debug = 1;
#endif
}

// Specialized constructor
Engine::Engine(const char * appName, const int width, const int height)
{
    strcpy_s(info.title, appName);
    info.windowWidth = width;
    info.windowHeight = height;

    info.majorVersion = 4;
    info.minorVersion = 0;

    info.samples = 0;
    info.flags.all = 0;
    info.flags.cursor = 1;
#ifdef _DEBUG
    info.flags.debug = 1;
#endif
}

Engine::~Engine() 
{

}

//-----------------------------------------------------
//  Engine:: Run()
//      The internal game loop that the engine runs on.
//-----------------------------------------------------
void Engine::Run()
{
    // Initialize
    this->preInitialize();
    this->Initialize();

    // Load Content
    this->preLoadContent();
    this->LoadContent();

    while( (glfwGetKey( GLFW_KEY_ESC ) == GLFW_RELEASE) && (glfwGetWindowParam( GLFW_OPENED ) != GL_FALSE) )
    {
        // Update loop
        Update((float)glfwGetTime());

        ClearBuffers();

        // Draw loop
        Draw();            

        glfwSwapBuffers();
    } 

    // Unload Content
    UnloadContent();
    glfwTerminate();
}

// Initialize
void Engine::preInitialize()
{
    app = this;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
}

// Load Content
void Engine::preLoadContent()
{
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, info.majorVersion);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, info.minorVersion);

#ifdef _DEBUG
    glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, info.samples);
    glfwOpenWindowHint(GLFW_STEREO, info.flags.stereo ? GL_TRUE : GL_FALSE);
    if (info.flags.fullscreen)
    {
        if (info.windowWidth == 0 || info.windowHeight == 0)
        {
            GLFWvidmode mode;
            glfwGetDesktopMode(&mode);
            info.windowWidth = mode.Width;
            info.windowHeight = mode.Height;
        }
        glfwOpenWindow(info.windowWidth, info.windowHeight, 8, 8, 8, 0, 32, 0, GLFW_FULLSCREEN);
        glfwSwapInterval((int)info.flags.vsync);
    }
    else
    {
        if (!glfwOpenWindow(info.windowWidth, info.windowHeight, 8, 8, 8, 0, 32, 0, GLFW_WINDOW))
        {
            fprintf(stderr, "Failed to open window\n");
            return;
        }
    }

    glfwSetWindowTitle(info.title);
    glfwSetWindowSizeCallback(glfw_onResize);
    glfwSetKeyCallback(glfw_onKey);
    glfwSetMouseButtonCallback(glfw_onMouseButton);
    glfwSetMousePosCallback(glfw_onMouseMove);
    glfwSetMouseWheelCallback(glfw_onMouseWheel);
    (info.flags.cursor ? glfwEnable : glfwDisable)(GLFW_MOUSE_CURSOR);

    info.flags.stereo = (glfwGetWindowParam(GLFW_STEREO) ? 1 : 0);

    gl3wInit();

//#ifdef _DEBUG
//    fprintf(stderr, "VENDOR: %s\n", (char *)glGetString(GL_VENDOR));
//    fprintf(stderr, "VERSION: %s\n", (char *)glGetString(GL_VERSION));
//    fprintf(stderr, "RENDERER: %s\n", (char *)glGetString(GL_RENDERER));
//#endif

    //if (info.flags.debug)
    //{
    //    if (gl3wIsSupported(4, 3))
    //    {
    //        glDebugMessageCallback(debug_callback, this);
    //        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    //    }
    //    else if (sb6IsExtensionSupported("GL_ARB_debug_output"))
    //    {
    //        glDebugMessageCallbackARB(debug_callback, this);
    //        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
    //    }
    //}


    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//-----------------------------------------------------------------
//  Engine:: ClearBuffers()
//      This allows the user to change how the buffers are cleared.
//-----------------------------------------------------------------

void Engine::ClearBuffers()
{
    const GLfloat grey[] = { 0.250f, 0.25f, 0.25f, 1.0f };
    const GLfloat one = 1.0f;

    glViewport(0, 0, info.windowWidth, info.windowHeight);
    glClearBufferfv(GL_COLOR, 0, grey);
    glClearBufferfv(GL_DEPTH, 0, &one);
}

//int sb6IsExtensionSupported(const char * extname)
//{
//    GLint numExtensions;
//    GLint i;
//
//    glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
//
//    for (i = 0; i < numExtensions; i++)
//    {
//        const GLubyte * e = glGetStringi(GL_EXTENSIONS, i);
//        if (!strcmp((const char *)e, extname))
//        {
//            return 1;
//        }
//    }
//
//    return 0;
//}

//============================================================

void Engine::OnResize(int w, int h)
{
    info.windowWidth = w;
    info.windowHeight = h;
}

void Engine::onKey(int key, int action)
{
    // Not used
    key;
    action;
}

void Engine::onMouseButton(int button, int action)
{
    // Not used
    button;
    action;
}

void Engine::onMouseMove(int x, int y)
{
    // Not used
    x;
    y;
}

void Engine::onMouseWheel(int pos)
{
    // Not used
    pos;
}

void Engine::onDebugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message)
{
#ifdef _WIN32
    OutputDebugStringA(message);
    OutputDebugStringA("\n");

    // Not used
    source;
    type;
    id;
    severity;
    length;
#endif
}

void Engine::getMousePosition(int& x, int& y)
{
    glfwGetMousePos(&x, &y);
}

void GLFWCALL Engine::glfw_onResize(int w, int h)
{
    app->OnResize(w, h);
}

void GLFWCALL Engine::glfw_onKey(int key, int action)
{
    app->onKey(key, action);
}

void GLFWCALL Engine::glfw_onMouseButton(int button, int action)
{
    app->onMouseButton(button, action);
}

void GLFWCALL Engine::glfw_onMouseMove(int x, int y)
{
    app->onMouseMove(x, y);
}

void GLFWCALL Engine::glfw_onMouseWheel(int pos)
{
    app->onMouseWheel(pos);
}

void Engine::setVsync(bool enable)
{
    info.flags.vsync = enable ? 1 : 0;
    glfwSwapInterval((int)info.flags.vsync);
}

void APIENTRY Engine::debug_callback(GLenum source,GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam)
{
    reinterpret_cast<Engine *>(userParam)->onDebugMessage(source, type, id, severity, length, message);
}