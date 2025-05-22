#include "Rey.h"

bool Rey::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {
    // El rey solo puede moverse una casilla en cualquier dirección
    int difFilas = filaDestino - filaOrigen;  //Cuántas filas se mueve el rey?
    if (difFilas < 0) difFilas = -difFilas;  //convierte la diferencia a valor absoluto

    int difCols = colDestino - colOrigen;  //Cuántas columnas se mueve el rey?
    if (difCols < 0) difCols = -difCols;  //convierte la diferencia a valor absoluto

    if (difFilas > 1 || difCols > 1)  //si el rey se mueve más de una casilla en cualquier dirección vertical, horizontal o diagonal
        return false;  //movimiento inválido retorna false


    return true;
}
