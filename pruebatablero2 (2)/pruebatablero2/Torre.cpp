#include "Torre.h"

bool Torre::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, tablero& Tablero) {
    // Solo permite movimiento en misma fila o columna
    if (filaOrigen != filaDestino && colOrigen != colDestino)
        return false;  //Si el movimiento no es ni en la misma fila ni en la misma columna devuelve un false 

    // Dirección de movimiento
    int pasoFila = 0;
    int pasoCol = 0;

    if (filaDestino > filaOrigen)  //si el destino está más arriba
        pasoFila = 1;
    else if (filaDestino < filaOrigen)  //si el destino está más abajo
        pasoFila = -1;

    if (colDestino > colOrigen)  //si el destino está a la derecga
        pasoCol = 1;
    else if (colDestino < colOrigen)  //si el destino está a la izquierda
        pasoCol = -1;

    int f = filaOrigen + pasoFila;
    int c = colOrigen + pasoCol;

    // Comprueba si hay piezas en el camino sin incluir destino
    while (f != filaDestino || c != colDestino) {  //recorre todas las casillas entre el origen y el destino
        if (Tablero.at(f, c).hayPieza())  //si encuentra una pieza en el camino devuelve false porque no puede saltarla
            return false;
        f += pasoFila;  //si no sigue avanzando
        c += pasoCol;   //si no sigue avanzando
    }


    return true;
}
