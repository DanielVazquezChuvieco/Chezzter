#include "Rey.h"

bool Rey::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {
    int difFilas = abs(filaDestino - filaOrigen);
    int difCols = abs(colDestino - colOrigen);
    if (intentaComerSuPropioRey(filaDestino, colDestino, Tablero))
        return false;

    // Movimiento solo 1 casilla
    if (difFilas > 1 || difCols > 1)
        return false;

    

}
