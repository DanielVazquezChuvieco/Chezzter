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
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino,const tablero& Tablero) override; // comprobacion movimiento valido rey

    bool esRey() const override { return true; } // definicion del metodo virtual de pieza para ver que es un rey
    std::string nombre() const { return "REY"; } //return nombre de la pieza

    Pieza* clonar() const override {             // clona la pieza 
        return new Rey(fila, columna, esBlanca()); 
    }


};

