#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
class Alfil :public Pieza
{
public:
    Alfil(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/alfilBlanco.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/alfilNegro.png", 1);

        setPosicionGrafica();
    } //Constructor 
};

