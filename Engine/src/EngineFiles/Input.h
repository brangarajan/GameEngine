#ifndef INPUT_H
#define INPUT_H

#include "KeyMapping.h"

class Input
{
public:
    Input();

    bool GetKeyState(KEY key);
    bool GetButtonState(BUTTON button);
    void GetCursor(int *&x, int *&y);
};

#endif