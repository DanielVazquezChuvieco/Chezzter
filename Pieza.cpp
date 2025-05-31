#include "Pieza.h"
#include "tablero.h"

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

void Pieza::setPosicionGraficaPixel(int x, int y) {
    sprite->setPos(x - 25, y - 25);
    sprite->setCenter(0.5f, 0.5f);  //Centra el sprite
    sprite->setSize(50, 50);  //Tamaño estándar
}

bool Pieza::intentaComerSuPropioRey(int filaDestino, int colDestino, const tablero& Tablero) const {
    Pieza* destino = Tablero.at(filaDestino, colDestino).getPieza();

    if (!destino) return false;              // No hay pieza en destino
    if (!destino->esRey()) return false;     // La pieza destino no es un rey
    if (destino->esBlanca() != esBlanca()) return false;  // El rey no es del mismo color

    return true;  // Es tu propio rey
}
