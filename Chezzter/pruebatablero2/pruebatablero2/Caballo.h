#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
class Caballo:public Pieza
{
public:
    Caballo(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/caballoBlanco.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/caballoNegro.png", 1);

        setPosicionGrafica();
    } //Constructor 
};

