#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include <iostream>

using namespace std;

class peon :public Pieza {
public:
    peon(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza) {
            sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
            cout << "PEON REAL BlNCO" << endl;
        }
        else {
            sprite = new ETSIDI::SpriteSequence("imagenes/peonNegro2.png", 1);
            cout << "PEON REAL NGR" << endl;
        }

        setPosicionGrafica();
    } //Constructor 

};



