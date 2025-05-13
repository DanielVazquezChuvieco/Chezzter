#pragma once
#include "ETSIDI.h"
#include "Pieza.h"

class peon :public Pieza {
public:
    peon(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/peonNegro2.png", 1);

        setPosicionGrafica();
    } //Constructor 

};



