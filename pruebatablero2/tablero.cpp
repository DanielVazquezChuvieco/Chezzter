#include "tablero.h"
#include "freeglut.h"


// Esta función se encarga de dibujar el tablero cuadrado por cuadrado
void tablero::dibuja() {
    bool esBlanco;
    // Recorremos todas las filas del tablero
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            // Usamos una fórmula para alternar colores blanco y negro
            esBlanco = (fila + col) % 2 == 0;

            // Si es una casilla blanca, usamos color blanco
            if (esBlanco)
                glColor3f(1.0f, 1.0f, 1.0f); //  blanco
            else
                glColor3f(0.8f, 0.5f, 0.2f); //  marron claro

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int x = col * tamañoCasilla; // columna * tamaño de casilla
            int y = fila * tamañoCasilla; // fila * tamaño de casilla

            // Dibujamos un cuadrado usando 4 vértices (OpenGL clásico)
            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2i(x, y);                           // esquina superior izquierda
            glVertex2i(x + tamañoCasilla, y);             // esquina superior derecha
            glVertex2i(x + tamañoCasilla, y + tamañoCasilla); // esquina inferior derecha
            glVertex2i(x, y + tamañoCasilla);             // esquina inferior izquierda
            glEnd(); // Terminamos el dibujo del cuadrado
        }
    }
}