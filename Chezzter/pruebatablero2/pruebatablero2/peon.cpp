#include "peon.h"


bool peon::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, tablero& Tablero) {
    int direccion = esBlancoPieza ? -1 : 1; // Define la dirección en la que se mueve el peón
    int filaInicial = esBlancoPieza ? 6 : 1; //Si es blanco, la dirección es -1(hacia arriba en el tablero)
    //Si es negro, la dirección es +1 (hacia abajo)

// Movimiento vertical simple
    if (colOrigen == colDestino) {  //El peón solo puede avanzar en la misma columna si no está capturando
        // Una casilla adelante
        if (filaDestino == filaOrigen + direccion && !Tablero.at(filaDestino, colDestino).hayPieza())
            return true;
        // Dos casillas adelante desde la posición inicial, y ambas deben estar vacías
        bool enPosicionInicial = (filaOrigen == filaInicial);
        bool avanzaDos = (filaDestino == filaOrigen + 2 * direccion);

        // la casilla intermedia y de destino deben estar libres
        bool intermediaLibre = !Tablero.at(filaOrigen + direccion, colDestino).hayPieza();
        bool destinoLibre = !Tablero.at(filaDestino, colDestino).hayPieza();

        if (enPosicionInicial && avanzaDos && intermediaLibre && destinoLibre)
            return true;
    }
    // Captura en diagonal
    bool esDiagonal = (abs(colDestino - colOrigen) == 1);  //abs devuelve el valor absoluto de un número ignorando si la diferencia entre columnas es negativa o positiva
    bool esAdelante = (filaDestino == filaOrigen + direccion); //Dirección adelante
    bool hayEnemigo = Tablero.at(filaDestino, colDestino).hayPieza() && Tablero.at(filaDestino, colDestino).getPieza()->getcolor() != esBlancoPieza; //Comprueba que sea del otro color

    if (esDiagonal && esAdelante && hayEnemigo)
        return true;
    return false;
}











