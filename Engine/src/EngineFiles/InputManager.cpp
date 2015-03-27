#include "InputManager.h"

InputManager::InputManager() { }

InputManager::~InputManager()
{
    delete this->input;
}

// Singleton
InputManager * InputManager::GetInstance() 
{
    static InputManager instance;
    return &instance;
}

void InputManager::Initialize()
{
    InputManager *manager = InputManager::GetInstance();
    manager->input = 0;
}

Input * InputManager::GetInput()
{
    InputManager *manager = InputManager::GetInstance();
    return manager->input; 
}