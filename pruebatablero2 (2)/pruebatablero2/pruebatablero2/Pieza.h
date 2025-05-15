#pragma once
#include "ETSIDI.h"

class Pieza
{
protected:
    int fila;
    int columna;
    bool esBlancoPieza;
    ETSIDI::SpriteSequence* sprite;
    static const int tama�oCasilla = 75;
    static const int margenX = 100;
    static const int margenY = 100;


public:
    void setFila(int f) { fila = f; }
    void setColumna(int c) { columna = c; }
    Pieza(int filaIni, int columnaIni, bool blanca) :fila(filaIni),
        columna(columnaIni), esBlancoPieza(blanca), sprite(nullptr) {
    }

    virtual ~Pieza() { delete sprite; }
    bool getcolor() const { return esBlancoPieza; }
    virtual void dibuja();
    void setPosicionGrafica();
};