#include "Pieza.h"


void Pieza::dibuja() {
    if (sprite) {
        sprite->draw();
    }
}

void Pieza::setPosicionGrafica() {
    float x = Constantes::margenX
        + columna * Constantes::tamanoCasilla + Constantes::tamanoCasilla / 2.0f;
    float y = Constantes::margenX
        + fila * Constantes::tamanoCasilla + Constantes::tamanoCasilla / 2.0f;
    sprite->setPos(x - 25, y - 25);
    sprite->setCenter(0.5f, 0.5f);
    sprite->setSize(50, 50);
}