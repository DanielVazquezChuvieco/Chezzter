#include "peon.h"
#include "freeglut.h"
//#include "tablero.h"

const int tamañoCasilla = 75;
const int margenX = 100;
const int margenY = 100;


void peon::dibuja() {
	float x = margenX + fila * tamañoCasilla;
	float centroX = x  + (tamañoCasilla) / 2.0f;
	float y = margenY + columna * tamañoCasilla;
	float centroY = y + (tamañoCasilla) / 2.0f;
    
    // Cambiar al modo MODELVIEW (necesario para usar glTranslate)
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix(); // Guardamos la matriz actual

    // Trasladamos la "pieza" al centro de la casilla (en 2D)
    glTranslatef(centroY, centroX, 0.0f);

    // Color del peón
    if (esBlanco)
        glColor3f(1.0f, 1.0f, 1.0f); // blanco
    else
        glColor3f(0.1f, 0.1f, 0.1f); // negro

    glutWireSphere(r, 20,20);

    glPopMatrix(); // Restauramos la matriz original
}



