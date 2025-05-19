#include "Alfil.h"
#include "tablero.h"
#include <cmath>

bool Alfil::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, tablero& Tablero) {
    // El alfil solo puede moverse en diagonal
    if (abs(filaDestino - filaOrigen) != abs(colDestino - colOrigen)) //sólo puede moverse si la distancia en filas y columnas es igual
        return false;  //si no, el movimiento no es válido y devuelve un false

    // Dirección de movimiento
    int pasoFila = 0;
    int pasoCol = 0;

    if (filaDestino > filaOrigen)
        pasoFila = 1;  //pasofila = 1 si va hacia abajo
    else if (filaDestino < filaOrigen)
        pasoFila = -1;  //pasofila = -1 si va hacia arriba

    if (colDestino > colOrigen)
        pasoCol = 1;   //pasocol = 1 si va la derecha
    else if (colDestino < colOrigen)
        pasoCol = -1;   //pasocol = -1 si va a la izquierda

    int f = filaOrigen + pasoFila;
    int c = colOrigen + pasoCol;

    // Comprueba si hay piezas en el camino (sin incluir destino)
    while (f != filaDestino && c != colDestino) {  //Recorre todas las casillas entre el origen y destino
        if (Tablero.at(f, c).hayPieza())  // si encuentra una pieza devuelve false, movimiento no válido
            return false;
        f += pasoFila;
        c += pasoCol;
    }

    return true;
}
