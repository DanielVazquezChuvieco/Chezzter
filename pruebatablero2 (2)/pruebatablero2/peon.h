#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include "tablero.h"

class peon :public Pieza {
public:
    peon(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/peonNegro2.png", 1);

        setPosicionGrafica();
    } //Constructor 



    //Movimiento v�lido pe�n
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) override;
};



