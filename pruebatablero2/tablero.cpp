#include "tablero.h"
#include "freeglut.h"


// Esta funci�n se encarga de dibujar el tablero cuadrado por cuadrado
void tablero::dibuja() {
    bool esBlanco;
    // Recorremos todas las filas del tablero
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            // Usamos una f�rmula para alternar colores blanco y negro
            esBlanco = (fila + col) % 2 == 0;

            // Si es una casilla blanca, usamos color blanco
            if (esBlanco)
                glColor3f(1.0f, 1.0f, 1.0f); //  blanco
            else
                glColor3f(0.8f, 0.5f, 0.2f); //  marron claro

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int x = col * tama�oCasilla; // columna * tama�o de casilla
            int y = fila * tama�oCasilla; // fila * tama�o de casilla

            // Dibujamos un cuadrado usando 4 v�rtices (OpenGL cl�sico)
            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2i(x, y);                           // esquina superior izquierda
            glVertex2i(x + tama�oCasilla, y);             // esquina superior derecha
            glVertex2i(x + tama�oCasilla, y + tama�oCasilla); // esquina inferior derecha
            glVertex2i(x, y + tama�oCasilla);             // esquina inferior izquierda
            glEnd(); // Terminamos el dibujo del cuadrado
        }
    }
}