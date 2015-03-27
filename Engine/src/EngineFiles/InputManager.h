#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Input.h"

class InputManager
{
public:
    ~InputManager();
    static void Initialize();

    static Input * GetInput();


private:
    InputManager();
    static InputManager * GetInstance();
    
    Input *input;
};

#endif