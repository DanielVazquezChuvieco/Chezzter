#include "Rey.h"

bool Rey::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero) {
    int difFilas = abs(filaDestino - filaOrigen);
    int difCols = abs(colDestino - colOrigen);
    if (intentaComerSuPropioRey(filaDestino, colDestino, Tablero))
        return false;

    // Movimiento solo 1 casilla
    if (difFilas > 1 || difCols > 1)
        return false;

    
    
   
    tablero copia = Tablero.copiar(); // Copiar el tablero para simular sin modificar el original

   
    Pieza* reyCopia = copia.at(filaOrigen, colOrigen).getPieza();  // Obtener puntero al rey dentro de la copia

    // Simular el movimiento
    copia.at(filaDestino, colDestino).set(reyCopia);

    copia.at(filaOrigen, colOrigen).set(nullptr);
    reyCopia->setFila(filaDestino);
    reyCopia->setColumna(colDestino);
    copia.aplicarGravedad();
   
    bool enJaque = copia.estaEnJaque(this->esBlanca()); // Comprobar si tras moverse el rey queda en jaque
    

    return !enJaque;
}
