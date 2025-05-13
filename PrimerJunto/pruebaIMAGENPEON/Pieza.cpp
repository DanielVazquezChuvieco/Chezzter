#include "Pieza.h"


void Pieza::dibuja() {
    if (sprite) {
<<<<<<< Updated upstream
=======
        glLoadIdentity();
>>>>>>> Stashed changes
        sprite->draw();
    }
}

void Pieza::setPosicionGrafica() {
    float x = margenX + columna * tamañoCasilla + tamañoCasilla / 2.0f;
    float y = margenY + fila * tamañoCasilla + tamañoCasilla / 2.0f;
    sprite->setPos(x - 25, y - 25);
    sprite->setCenter(0.5f, 0.5f);
    sprite->setSize(50, 50);
}