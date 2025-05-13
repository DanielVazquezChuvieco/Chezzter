#include "tablero.h"
#include "peon.h"
#include "freeglut.h"
#include "Caballo.h"
#include "Torre.h"
#include "Alfil.h"
#include "Rey.h"
#include "Reina.h"
#include "ETSIDI.h"


Casilla casilla; //Asignamos la responsabilidad de definir el tama�o de la casilla a casilla

// Esta funci�n se encarga de dibujar el tablero cuadrado por cuadrado
tablero::tablero() {
    grid.resize(filas, std::vector<Casilla>(columnas));  // crea un grid de 8x8
    colocapiezas();
}
Casilla& tablero::at(int fila, int columna) {
    return grid[fila][columna];
}
void tablero::dibuja() {
    //Importante que este antes del resto de dibujos para que no se pinte por encima
    // Fondo con textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
    glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

    glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

    glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
    glTexCoord2d(0, 1); glVertex2f(0, 0); //Limite abajo izquierda
    glTexCoord2d(1, 1); glVertex2f(800, 0); //Limite abajo derecha
    glTexCoord2d(1, 0); glVertex2f(800, 800); //Limite arriba derecha
    glTexCoord2d(0, 0); glVertex2f(0, 800); //Origen arriba izq
    glEnd();

   // glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

   

    // Recorremos todas las filas del tablero
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            // Usamos una f�rmula para alternar colores blanco y negro
            esBlanco = (fila + col) % 2 == 0;

            // Si es una casilla blanca, usamos color blanco
            if (esBlanco)
                glColor3f(0.95f, 0.95f, 0.95f); //  gris claro
            else
                glColor3f(1.0f, 0.4f, 0.4f); //  rojo claro

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int y = margenY + col * casilla.gettam(); // columna * tama�o de casilla
            int x = margenX + fila * casilla.gettam(); // fila * tama�o de casilla



            // Dibujamos un cuadrado usando 4 v�rtices (OpenGL cl�sico)
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
        glColor3f(0.1f, 0.1f, 0.1f); // color negro
        glRasterPos2f(margenX + casilla.gettam() / 2 + col * casilla.gettam(), 75); //Encargada de posicionar el caracter
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter); //Escribe en la tipologia elegida el caracter
    }
    for (int fila = 0; fila < filas; fila++) {
        char caracter = '1' + fila;
        glColor3f(0.1f, 0.1f, 0.1f); // color negro
        glRasterPos2f(75, margenY + casilla.gettam() / 2 + fila * casilla.gettam());
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter);
    }
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            if (grid[fila][col].hayPieza()) {
                grid[fila][col].getPieza()->dibuja();  // Llamamos al m�todo dibuja() de la pieza
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

    //Caballos
        at(7, 1).set(new Caballo(7, 1, true));  // true = blanco
        at(7, 6).set(new Caballo(7, 6, true));  // true = blanco
    // Caballos negros
        at(0, 1).set(new Caballo(0, 1, false));  // false = negro
        at(0, 6).set(new Caballo(0, 6, false));  //false = negro

        //Alfiles
        at(7, 2).set(new Alfil(7, 2, true));  // true = blanco
        at(7, 5).set(new Alfil(7, 5, true));  // true = blanco
        // Alfiles negros
        at(0, 2).set(new Alfil(0, 2, false));  // false = negro
        at(0, 5).set(new Alfil(0, 5, false));  //false = negro

        //Torres
        at(7, 0).set(new Torre(7, 0, true));  // true = blanco
        at(7, 7).set(new Torre(7, 7, true));  // true = blanco
        // Torres negros
        at(0, 0).set(new Torre(0, 0, false));  // false = negro
        at(0, 7).set(new Torre(0, 7, false));  //false = negro

        //Reina
        at(7, 3).set(new Reina(7, 3, true));  // true = blanco
        // Reina negros 
        at(0, 4).set(new Reina(0, 4, false));  // false = negro

        //Rey
        at(7, 4).set(new Rey(7, 4, true));  // true = blanco
        // Rey negros 
        at(0, 3).set(new Rey(0, 3, false));  // false = negro

}