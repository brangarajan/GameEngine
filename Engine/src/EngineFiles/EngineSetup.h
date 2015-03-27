#ifndef ENGINE_SETUP_H
#define ENGINE_SETUP_H

#ifdef WIN32
    #pragma once
    #define _CRT_SECURE_NO_WARNINGS 1

    #define WIN32_LEAN_AND_MEAN 1
    #include <Windows.h>

    #ifdef _DEBUG
        #ifdef _WIN64
            #pragma comment (lib, "GLFW_d64.lib")
        #else
            #pragma comment (lib, "GLFW_Debug.lib")
        #endif

    #else
        #ifdef _WIN64
            #pragma comment (lib, "GLFW_r64.lib")
        #else
            #pragma comment (lib, "GLFW_r32.lib")
        #endif
    #endif

    #pragma comment (lib, "OpenGL32.lib")
#endif

#endif