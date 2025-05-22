#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include "tablero.h"

class Rey :public Pieza
{
public:
    Rey(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/reyBlanco.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/reyNegro.png", 1);

        setPosicionGrafica();
    } //Constructor


    //Movimiento válido rey
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino,const tablero& Tablero) override;

    bool esRey() const override { return true; }



};

