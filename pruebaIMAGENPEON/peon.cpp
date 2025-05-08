#include "peon.h"

const int tamañoCasilla = 75;
const int margenX = 100;
const int margenY = 100;

peon::peon(int filaIni, int columnaIni, bool blanca){
    // Guardamos los valores que nos pasan
    fila = filaIni;
    columna = columnaIni;
    esBlanco = blanca;

    // Elegimos la imagen según si es blanco o negro
    if (esBlanco) {        //Usamos new que sirve para construir el objeto justo cuando ya se cual de las
                            //dos voy a usar
        sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
    }
    else {
        sprite = new ETSIDI::SpriteSequence("imagenes/peonNegro2.png", 1);
    }

    float x, y;
    // Calculamos la posición gráfica del peón en el centro de la casilla
    x = margenX + columna * tamañoCasilla + tamañoCasilla / 2.0f;
    y = margenY + fila * tamañoCasilla + tamañoCasilla / 2.0f;

    // Posicionamos el sprite
    sprite->setPos(x - 25, y - 25);  // posicion, me ha tocado ajustar manualmente por la imagen PNG
    sprite->setCenter(0.5f, 0.5f);   // el centro de la imagen
    sprite->setSize(50, 50);        // tamaño 
    //nos toca usar -> ya que hemos usado un puntero y asi accedemos a sus funciones
}

void peon::dibuja() {
   
        // Dibujar sprite del peón
        sprite->draw();
}





