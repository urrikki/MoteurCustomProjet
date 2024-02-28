#pragma once
#include "Framework.h"
#include <Windows.h>

class Input {
public:
    static bool isKeyPressed(char key);
    static POINT getMouseDelta();
    static void update(HWND hWnd);
};