#include "peon.h"

bool peon::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {
    int direccion = esBlancoPieza ? -1 : 1;
    int columnaInicial = esBlancoPieza ? 6 : 1;

    if (intentaComerSuPropioRey(filaDestino, colDestino, Tablero))
        return false;

    // Movimiento hacia adelante (mismo fila, cambia columna)
    if (filaOrigen == filaDestino) {
        // Una casilla adelante
        if (colDestino == colOrigen + direccion) {
            if (colDestino >= 0 && colDestino < 8 && !Tablero.at(filaDestino, colDestino).hayPieza())
                return true;
        }

        // Dos casillas desde posición inicial
        if (colOrigen == columnaInicial && colDestino == colOrigen + 2 * direccion) {
            int intermedia = colOrigen + direccion;
            if (intermedia >= 0 && intermedia < 8 && colDestino >= 0 && colDestino < 8 &&
                !Tablero.at(filaDestino, intermedia).hayPieza() &&
                !Tablero.at(filaDestino, colDestino).hayPieza()) {
                return true;
            }
        }
    }

    // Captura vertical (una fila arriba o abajo)
    bool esMovimientoDiagonal = abs(filaDestino - filaOrigen) == 1;
    bool esHaciaAdelante = colDestino == colOrigen + direccion;
    bool hayPieza = (colDestino >= 0 && colDestino < 8 && filaDestino >= 0 && filaDestino < 8)
        ? Tablero.at(filaDestino, colDestino).hayPieza()
        : false;

    if (esMovimientoDiagonal && esHaciaAdelante && hayPieza)
        return true;

    return false;
}









