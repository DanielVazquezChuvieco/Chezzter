#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
class Torre :public Pieza
{
public:
    Torre(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/torreBlanca.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/torreNegra.png", 1);

        setPosicionGrafica();
    } //Constructor 
};


