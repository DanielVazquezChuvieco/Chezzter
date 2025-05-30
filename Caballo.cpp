#include "Caballo.h"
#include <cmath>

bool Caballo::movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino,const tablero& Tablero) {
    if (intentaComerSuPropioRey(filaDestino, colDestino, Tablero))
        return false;

    // Calcula la diferencia absoluta de filas y columnas
    int diferenciaFilas = filaDestino - filaOrigen; //Diferencia filas
    if (diferenciaFilas < 0) diferenciaFilas = -diferenciaFilas;  //en valor absoluto, pues da igual que se mueva a la izquierda o a la derecha siempre es positivo

    int diferenciaColumnas = colDestino - colOrigen; //Diferencia columnas
    if (diferenciaColumnas < 0) diferenciaColumnas = -diferenciaColumnas;  ////en valor absoluto, pues da igual que se mueva a la izquierda o a la derecha siempre es positivo

    // El caballo se mueve en L: 2 en una dirección y 1 en la otra
    bool esMovimientoL = (diferenciaFilas == 2 && diferenciaColumnas == 1) || (diferenciaFilas == 1 && diferenciaColumnas == 2);  //el caballo solo puede moerse dos casillas en una direccion y una en la otra, ya sean columnas o filas

    if (!esMovimientoL)   //si no es así
        return false;   //devuelve false


    return true;
}