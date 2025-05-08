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
                 glColor3f(0.5f, 0.5f, 0.5f); //  gris claro
            else
                glColor3f(0.8f, 0.5f, 0.2f); //  marron claro

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int y = margenY + col * tama�oCasilla; // columna * tama�o de casilla
            int x = margenX + fila * tama�oCasilla; // fila * tama�o de casilla

            // Dibujamos un cuadrado usando 4 v�rtices (OpenGL cl�sico)
            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2i(x, y);                           // esquina superior izquierda
            glVertex2i(x + tama�oCasilla, y);             // esquina superior derecha
            glVertex2i(x + tama�oCasilla, y + tama�oCasilla); // esquina inferior derecha
            glVertex2i(x, y + tama�oCasilla);             // esquina inferior izquierda
            glEnd(); // Terminamos el dibujo del cuadrado
        }
    }

    //Estas funciones se encargan de asignar letras y numeros a las casillas
    for (int col = 0; col < columnas; col++) {
        char caracter = 'a' + col;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(margenX+ tama�oCasilla/2 + col * tama�oCasilla, 75); //Encargada de posicionar el caracter
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter); //Escribe en la tipologia elegida el caracter
    }
    for (int fila = 0; fila < filas; fila++) {
        char caracter = '1' + fila;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(75, margenY + tama�oCasilla / 2 + fila * tama�oCasilla);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter);
    }
}