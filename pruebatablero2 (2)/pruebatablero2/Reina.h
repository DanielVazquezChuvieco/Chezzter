#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include "tablero.h"

class Reina :public Pieza
{
public:
    Reina(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/reinaBlanca.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/reinaNegra.png", 1);

        setPosicionGrafica();
    } //Constructor 

    //Movimiento válido reina
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, tablero& Tablero) override;
};
