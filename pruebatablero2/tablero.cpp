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
                 glColor3f(0.5f, 0.5f, 0.5f); //  gris claro
            else
                glColor3f(0.8f, 0.5f, 0.2f); //  marron claro

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int y = margenY + col * tamañoCasilla; // columna * tamaño de casilla
            int x = margenX + fila * tamañoCasilla; // fila * tamaño de casilla

            // Dibujamos un cuadrado usando 4 vértices (OpenGL clásico)
            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2i(x, y);                           // esquina superior izquierda
            glVertex2i(x + tamañoCasilla, y);             // esquina superior derecha
            glVertex2i(x + tamañoCasilla, y + tamañoCasilla); // esquina inferior derecha
            glVertex2i(x, y + tamañoCasilla);             // esquina inferior izquierda
            glEnd(); // Terminamos el dibujo del cuadrado
        }
    }

    //Estas funciones se encargan de asignar letras y numeros a las casillas
    for (int col = 0; col < columnas; col++) {
        char caracter = 'a' + col;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(margenX+ tamañoCasilla/2 + col * tamañoCasilla, 75); //Encargada de posicionar el caracter
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter); //Escribe en la tipologia elegida el caracter
    }
    for (int fila = 0; fila < filas; fila++) {
        char caracter = '1' + fila;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(75, margenY + tamañoCasilla / 2 + fila * tamañoCasilla);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter);
    }
}