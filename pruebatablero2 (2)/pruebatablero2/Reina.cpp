#include "Reina.h"

bool Reina::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {

    // Movimiento en misma fila o columna
    if (filaOrigen == filaDestino || colOrigen == colDestino) {

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

        // No puede capturar piezas propias
        if (Tablero.at(filaDestino, colDestino).hayPieza() && Tablero.at(filaDestino, colDestino).getPieza()->esBlanca() == esBlancoPieza)
            return false;
        return true;
    }
    // Movimiento en diagonal
    if (abs(filaDestino - filaOrigen) == abs(colDestino - colOrigen)) {

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
    return false;  //si no es ni recto ni diagonal devuelve false
}