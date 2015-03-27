#include "Input.h"
#include "sb6.h"

Input::Input() { }

bool Input::GetKeyState(KEY key)
{
    bool status;

    if (glfwGetKey(key) == GLFW_PRESS)
    {
        status = true;
    }

    else
    {
        status = false;
    }

    return status;
}

bool Input::GetButtonState(BUTTON button)
{
    bool status;

    if (glfwGetMouseButton(button) == GLFW_PRESS)
    {
        status = true;
    }

    else
    {
        status = false;
    }

    return status;
}

void Input::GetCursor(int *&x, int *&y)
{
    x = 0;
    y = 0;

    glfwGetMousePos(x, y);
}