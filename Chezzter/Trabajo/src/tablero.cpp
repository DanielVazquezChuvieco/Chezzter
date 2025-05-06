#include "tablero.h"
#include "freeglut.h"

void tablero::dibujaTablero()  //Función para dibujar el tablero
{
    for (int fila = 0; fila < FILAS; fila++) {
        for (int col = 0; col < COLUMNAS; col++) {
            // Color alternado
            if ((fila + col) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f);  // Blanco
            else
                glColor3f(0.36f, 0.25f, 0.20f);  // Marrón oscuro

            float x = col * TAMAÑO_CASILLA;
            float y = fila * TAMAÑO_CASILLA;

            //Dibuja
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + TAMAÑO_CASILLA, y);
            glVertex2f(x + TAMAÑO_CASILLA, y + TAMAÑO_CASILLA);
            glVertex2f(x, y + TAMAÑO_CASILLA);
            glEnd();
        }
    }
};