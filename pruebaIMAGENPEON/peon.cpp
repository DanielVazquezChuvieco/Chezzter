#include "peon.h"

const int tama�oCasilla = 75;
const int margenX = 100;
const int margenY = 100;

peon::peon(int filaIni, int columnaIni, bool blanca){
    // Guardamos los valores que nos pasan
    fila = filaIni;
    columna = columnaIni;
    esBlanco = blanca;

    // Elegimos la imagen seg�n si es blanco o negro
    if (esBlanco) {        //Usamos new que sirve para construir el objeto justo cuando ya se cual de las
                            //dos voy a usar
        sprite = new ETSIDI::SpriteSequence("imagenes/peonBlanco2.png", 1);
    }
    else {
        sprite = new ETSIDI::SpriteSequence("imagenes/peonNegro2.png", 1);
    }

    float x, y;
    // Calculamos la posici�n gr�fica del pe�n en el centro de la casilla
    x = margenX + columna * tama�oCasilla + tama�oCasilla / 2.0f;
    y = margenY + fila * tama�oCasilla + tama�oCasilla / 2.0f;

    // Posicionamos el sprite
    sprite->setPos(x - 25, y - 25);  // posicion, me ha tocado ajustar manualmente por la imagen PNG
    sprite->setCenter(0.5f, 0.5f);   // el centro de la imagen
    sprite->setSize(50, 50);        // tama�o 
    //nos toca usar -> ya que hemos usado un puntero y asi accedemos a sus funciones
}

void peon::dibuja() {
   
        // Dibujar sprite del pe�n
        sprite->draw();
}





