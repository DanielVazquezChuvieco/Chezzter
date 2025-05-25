#pragma once
#include "ETSIDI.h"
#include "Pieza.h"
#include "tablero.h"

class Caballo :public Pieza
{
public:
    Caballo(int filaIni, int columnaIni, bool blanca) :Pieza(filaIni, columnaIni, blanca) {
        if (esBlancoPieza)
            sprite = new ETSIDI::SpriteSequence("imagenes/caballoBlanco.png", 1);
        else
            sprite = new ETSIDI::SpriteSequence("imagenes/caballoNegro.png", 1);

        setPosicionGrafica();
    } //Constructor 

    //movimiento válido caballo
    bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) override;
    std::string nombre() const { return "CABALLO"; }
    Pieza* clonar() const override {
        return new Caballo(fila, columna, esBlanca());
    }

};

