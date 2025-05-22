#include "Rey.h"

bool Rey::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {
    // El rey solo puede moverse una casilla en cualquier direcci�n
    int difFilas = filaDestino - filaOrigen;  //Cu�ntas filas se mueve el rey?
    if (difFilas < 0) difFilas = -difFilas;  //convierte la diferencia a valor absoluto

    int difCols = colDestino - colOrigen;  //Cu�ntas columnas se mueve el rey?
    if (difCols < 0) difCols = -difCols;  //convierte la diferencia a valor absoluto

    if (difFilas > 1 || difCols > 1)  //si el rey se mueve m�s de una casilla en cualquier direcci�n vertical, horizontal o diagonal
        return false;  //movimiento inv�lido retorna false


    return true;
}
