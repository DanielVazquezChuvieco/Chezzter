#pragma once
#include "ETSIDI.h"

class Pieza
{
protected:
    int fila;
    int columna;
    bool esBlancoPieza;
    ETSIDI::SpriteSequence* sprite;
    static const int tamañoCasilla = 75;
    static const int margenX = 100;
    static const int margenY = 100;


public:
    Pieza(int filaIni, int columnaIni, bool blanca) :fila(filaIni), 
     columna(columnaIni), esBlancoPieza(blanca),sprite(nullptr){}

    virtual ~Pieza() { delete sprite;}
	bool getcolor() const{ return esBlancoPieza; }
    virtual void dibuja();
    void setPosicionGrafica();
};

