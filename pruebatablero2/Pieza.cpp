#include "Pieza.h"


void Pieza::dibuja() {
    if (sprite) {
        sprite->draw();
    }
}

void Pieza::setPosicionGrafica() {
    float x = margenX + columna * tama�oCasilla + tama�oCasilla / 2.0f;
    float y = margenY + fila * tama�oCasilla + tama�oCasilla / 2.0f;
    sprite->setPos(x - 25, y - 25);
    sprite->setCenter(0.5f, 0.5f);
    sprite->setSize(50, 50);
}