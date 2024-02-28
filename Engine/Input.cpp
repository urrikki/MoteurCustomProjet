#include "Input.h"
#include <iostream>

#include "Input.h"

// Définition des variables statiques pour stocker l'état des touches
static bool keys[256] = { false };

// Variable statique pour stocker la position de la souris précédente
static POINT prevMousePos = { 0 };

bool Input::isKeyPressed(char key) {
    return keys[key];
}

POINT Input::getMouseDelta() {
    POINT currentMousePos;
    GetCursorPos(&currentMousePos);
    ScreenToClient(GetActiveWindow(), &currentMousePos);
    POINT delta = { currentMousePos.x - prevMousePos.x, currentMousePos.y - prevMousePos.y };
    prevMousePos = currentMousePos;
    return delta;
}

void Input::update(HWND hWnd) {
    // Mise à jour de l'état des touches
    for (int i = 0; i < 256; ++i) {
        keys[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }

    // Mise à jour de la position de la souris
    POINT currentMousePos;
    GetCursorPos(&currentMousePos);
    ScreenToClient(hWnd, &currentMousePos);
    prevMousePos = currentMousePos;
}