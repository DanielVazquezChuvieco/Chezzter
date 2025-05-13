#include "tablero.h"
#include "peon.h"
#include "freeglut.h"
<<<<<<< Updated upstream
=======
#include <iostream>
using namespace std;
>>>>>>> Stashed changes

Casilla casilla; //Asignamos la responsabilidad de definir el tamaño de la casilla a casilla

// Esta función se encarga de dibujar el tablero cuadrado por cuadrado
tablero::tablero() {
    grid.resize(filas, std::vector<Casilla>(columnas));  // crea un grid de 8x8
    colocapiezas();
}
Casilla& tablero::at(int fila, int columna) {
    return grid[fila][columna];
}
void tablero::dibuja() {
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
            int y = margenY + col * casilla.gettam(); // columna * tamaño de casilla
            int x = margenX + fila * casilla.gettam(); // fila * tamaño de casilla

            // Dibujamos un cuadrado usando 4 vértices (OpenGL clásico)
            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2f(x, y);                           // esquina superior izquierda
            glVertex2f(x + casilla.gettam(), y);             // esquina superior derecha
            glVertex2f(x + casilla.gettam(), y + casilla.gettam()); // esquina inferior derecha
            glVertex2f(x, y + casilla.gettam());             // esquina inferior izquierda
            glEnd(); // Terminamos el dibujo del cuadrado
          
        }
    }

    //Estas funciones se encargan de asignar letras y numeros a las casillas
    for (int col = 0; col < columnas; col++) {
        char caracter = 'a' + col;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(margenX+ casilla.gettam() /2 + col * casilla.gettam(), 75); //Encargada de posicionar el caracter
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter); //Escribe en la tipologia elegida el caracter
    }
    for (int fila = 0; fila < filas; fila++) {
        char caracter = '1' + fila;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(75, margenY + casilla.gettam() / 2 + fila * casilla.gettam());
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter);
    }
<<<<<<< Updated upstream
=======
  
>>>>>>> Stashed changes
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            if (grid[fila][col].hayPieza()) {
<<<<<<< Updated upstream
                grid[fila][col].getPieza()->dibuja();  // Llamamos al método dibuja() de la pieza
=======
                grid[fila][col].getPieza()->dibuja();  // Llamamos al método dibuja()
                std::cout << "Dibujando pieza en " << fila << "," << col << std::endl;
>>>>>>> Stashed changes
            }
        }
    }
}
void tablero::colocapiezas() {
    for (int col = 0; col < columnas; ++col) {
        at(6, col).set(new peon(6, col, true));  // true = blanco
    }

    // Peones negros (fila 1)
    for (int col = 0; col < columnas; ++col) {
        at(1, col).set(new peon(1, col, false));  // false = negro
    }
<<<<<<< Updated upstream

=======
  
>>>>>>> Stashed changes
}