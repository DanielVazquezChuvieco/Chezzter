#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include "tablero.h"


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

    //Movimiento válido torre
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) override;

    std::string nombre() const{ return "TORRE"; } 
};


