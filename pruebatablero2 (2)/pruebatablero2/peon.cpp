#include "peon.h"

bool peon::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {
    int direccion = esBlancoPieza ? -1 : 1; // Blancos se mueven a la izquierda, negros a la derecha
    int columnaInicial = esBlancoPieza ? 6 : 1; // Columna desde la que pueden avanzar 2 pasos
    if (intentaComerSuPropioRey(filaDestino, colDestino, Tablero))
        return false;

    // Movimiento horizontal simple
    if (filaOrigen == filaDestino) {
        // Una casilla hacia adelante
        if (colDestino == colOrigen + direccion && !Tablero.at(filaDestino, colDestino).hayPieza())
            return true;

        // Dos casillas desde la posición inicial
        bool enPosicionInicial = (colOrigen == columnaInicial);
        bool avanzaDos = (colDestino == colOrigen + 2 * direccion);

        bool intermediaLibre = !Tablero.at(filaDestino, colOrigen + direccion).hayPieza();
        bool destinoLibre = !Tablero.at(filaDestino, colDestino).hayPieza();

        if (enPosicionInicial && avanzaDos && intermediaLibre && destinoLibre)
            return true;
    }

    // Captura en vertical (una fila arriba o abajo)
    bool esVertical = abs(filaDestino - filaOrigen) == 1;
    bool esAdelante = colDestino == colOrigen + direccion;
    bool hayPieza = Tablero.at(filaDestino, colDestino).hayPieza();

    if (esVertical && esAdelante && hayPieza)
        return true;

    return false;
}









