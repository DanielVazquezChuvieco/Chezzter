#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include "tablero.h"


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

    //movimiento válido alfil
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, tablero& Tablero);
};

