#include "Input.h"
#include <iostream>

int main() {
    //////////////////////////////////
    //////////// TEST ////////////////
    //////////////////////////////////
    while (true) {
        Input::update(nullptr); 

        // Vérifier si les touches Z, Q, S, D sont enfoncées
        if (Input::isKeyPressed('Z')) {
            std::cout << "Touche Z enfoncee" << std::endl;
        }
        if (Input::isKeyPressed('Q')) {
            std::cout << "Touche Q enfoncee" << std::endl;
        }
        if (Input::isKeyPressed('S')) {
            std::cout << "Touche S enfoncee" << std::endl;
        }
        if (Input::isKeyPressed('D')) {
            std::cout << "Touche D enfoncee" << std::endl;
        }

        POINT mouseDelta = Input::getMouseDelta();
        //std::cout << "Deplacement de la souris : X=" << mouseDelta.x << ", Y=" << mouseDelta.y << std::endl;

        // Vérifier si le bouton gauche de la souris est cliqué
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            std::cout << "Clic gauche de la souris enfonce" << std::endl;
        }

        Sleep(100);
    }

    return 0;
}
