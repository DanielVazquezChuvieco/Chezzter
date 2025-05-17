#include "Texto.h"
#include "ETSIDI.h"

void Texto::dibujar() {
    ETSIDI::setFont("fuentes/fuente_astronauta.ttf", 24);
    glColor3f(1, 1, 1); // blanco

    ETSIDI::printxy("AJEDREZ ORBITAL", -5, 12); // título

    glColor3f(0.8f, 0.8f, 0.8f); // gris clarito para el menú
    ETSIDI::printxy("1 - JUGAR", -4, 9);
    ETSIDI::printxy("2 - INSTRUCCIONES", -4, 7);
    ETSIDI::printxy("3 - CONTROLES", -4, 5);
    ETSIDI::printxy("4 - SALIR", -4, 3);

  
}
