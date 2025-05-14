#pragma once
<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include "ETSIDI.h"
#include "Pieza.h"

class peon:public Pieza {
public:
    peon(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if(esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
=======
=======
>>>>>>> Stashed changes
#include <iostream>
#include "ETSIDI.h"
#include "Pieza.h"
using namespace std;
class peon:public Pieza {
public:
    peon(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        std::cout << "Creando peon en fila " << filaIni << ", columna " << columnaIni << "\n";

        if (esBlancoPieza) 
            sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
            
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/peonNegro2.png", 1);

        setPosicionGrafica();
    } //Constructor 
  
};



