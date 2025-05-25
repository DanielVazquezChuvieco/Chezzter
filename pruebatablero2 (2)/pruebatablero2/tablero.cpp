#include "tablero.h"
#include "peon.h"
#include "freeglut.h"
#include "Caballo.h"
#include "Torre.h"
#include "Alfil.h"
#include "Rey.h"
#include "Reina.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;




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
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/FONDO1.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
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
                glColor3f(0.2f, 0.2f, 0.6f); //  gris claro
            else
                glColor3f(0.0f, 1.0f, 0.3f); //  rojo claro

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int y = Constantes::margenX
                + col * Constantes::tamanoCasilla; // columna * tama�o de casilla
            int x = Constantes::margenX
                + fila * Constantes::tamanoCasilla; // fila * tama�o de casilla



            // Dibujamos un cuadrado usando 4 v�rtices (OpenGL cl�sico)
            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2f(x, y);                           // esquina superior izquierda
            glVertex2f(x + Constantes::tamanoCasilla, y);             // esquina superior derecha
            glVertex2f(x + Constantes::tamanoCasilla, y + Constantes::tamanoCasilla); // esquina inferior derecha
            glVertex2f(x, y + Constantes::tamanoCasilla);             // esquina inferior izquierda
            glEnd(); // Terminamos el dibujo del cuadrado



        }
    }

    //Estas funciones se encargan de asignar letras y numeros a las casillas
    for (int col = 0; col < columnas; col++) {
        char caracter = 'a' + col;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(Constantes::margenX
            + Constantes::tamanoCasilla / 2 + col * Constantes::tamanoCasilla, 75); //Encargada de posicionar el caracter
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter); //Escribe en la tipologia elegida el caracter
    }
    for (int fila = 0; fila < filas; fila++) {
        char caracter = '1' + fila;
        glColor3f(1.0f, 1.0f, 1.0f); // color negro
        glRasterPos2f(75, Constantes::margenX
            + Constantes::tamanoCasilla / 2 + fila * Constantes::tamanoCasilla);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter);
    }
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            if (grid[fila][col].hayPieza()) {
                grid[fila][col].getPieza()->dibuja();  // Llamamos al m�todo dibuja() de la pieza
                //cout << "pieza" << fila << col << endl;
            }
        }
    }
}
/*
// PROBAR JAQUE MATE
void tablero::colocapiezas() {
    // Limpiar tablero
    for (int fila = 0; fila < filas; ++fila)
        for (int col = 0; col < columnas; ++col)
            at(fila, col).set(nullptr);

 
    at(7, 0).set(new Rey(7, 0, false));  


    at(5, 2).set(new Rey(5, 2, true));   

   
    at(0, 7).set(new Torre(0, 7, true));


    at(6, 2).set(new Torre(6, 2, true)); 
}
*/

void tablero::colocapiezas() {
    for (int fil = 0; fil < filas; ++fil) {
        at(fil, 6).set(new peon(fil, 6, true));  // true = blanco
    }

    // Peones negros (fila 1)
    for (int fil = 0; fil < filas; ++fil) {
        at(fil, 1).set(new peon(fil, 1, false));  // false = negro
    }

    //Caballos
    at(1, 7).set(new Caballo(1, 7, true));  // true = blanco
    at(6, 7).set(new Caballo(6, 7, true));  // true = blanco
    // Caballos negros
    at(1, 0).set(new Caballo(1, 0, false));  // false = negro
    at(6, 0).set(new Caballo(6, 0, false));  //false = negro

    //Alfiles
    at(2, 7).set(new Alfil(2, 7, true));  // true = blanco
    at(5, 7).set(new Alfil(5, 7, true));  // true = blanco
    // Alfiles negros
    at(2, 0).set(new Alfil(2, 0, false));  // false = negro
    at(5, 0).set(new Alfil(5, 0, false));  //false = negro

    //Torres
    at(0, 7).set(new Torre(0, 7, true));  // true = blanco
    at(7, 7).set(new Torre(7, 7, true));  // true = blanco
    // Torres negros
    at(0, 0).set(new Torre(0, 0, false));  // false = negro
    at(7, 0).set(new Torre(7, 0, false));  //false = negro

    //Reina
    at(4, 7).set(new Reina(4, 7, true));  // true = blanco
    // Reina negros 
    at(4, 0).set(new Reina(4, 0, false));  // false = negro

    //Rey
    at(3, 7).set(new Rey(3, 7, true));  // true = blanco
    // Rey negros 
    at(3, 0).set(new Rey(3, 0, false));  // false = negro

}


void tablero::aplicarGravedad() {
    for (int col = 0; col < columnas; ++col) { //recorre todas las columnas
        for (int fila = filas - 2; fila >= 0; --fila) { // recorre todas las filas desde la penultima(no puede caer más si esta en la última)
            if (grid[fila][col].hayPieza()) { //verifica si hay pieza
                int nuevaFila = fila; //guarda fila acyual pieza
                while (nuevaFila + 1 < filas && !grid[nuevaFila + 1][col].hayPieza()) {// recorre de la fila siguiente hasta que encuentre una pieza
                    nuevaFila++;
                }
                if (nuevaFila != fila) { // si la nueva fila es distinta de la fila inicial
                    Pieza* pieza = grid[fila][col].getPieza();// cogemos la pieza original(el puntero)
                    grid[nuevaFila][col].set(pieza);//la colocamos en la nueva fila
                    grid[fila][col].set(nullptr);//liberamos la anterior
                    pieza->setFila(nuevaFila);//actualiza posicíon interna
                    pieza->setColumna(col);
                    pieza->setPosicionGrafica(); // actualiza visualmente la pieza
                }
            }
        }
    }
}

Pieza* tablero::encontrarRey(bool colorBlanco, int& filaRey, int& colRey) const {
    for (int fila = 0; fila < 8; ++fila) {
        for (int col = 0; col < 8; ++col) {
            if (grid[fila][col].hayPieza()) {
                Pieza* p = grid[fila][col].getPieza();
                if (p->esRey() && p->esBlanca() == colorBlanco) {
                    filaRey = fila;
                    colRey = col;
                    return p;
                }
            }
        }
    }
    return nullptr;
}
bool tablero::estaEnJaque(bool colorBlanco) const {
    int filaRey, colRey;
    if (!encontrarRey(colorBlanco, filaRey, colRey)) return false;

    for (int fila = 0; fila < 8; ++fila) {
        for (int col = 0; col < 8; ++col) {
            if (grid[fila][col].hayPieza()) {
                Pieza* pieza = grid[fila][col].getPieza();
                if (pieza->esBlanca() != colorBlanco) { // enemigo
                    if (pieza->movimientoValido(fila, col, filaRey, colRey, *this)) {
                        cout << "Rey en (" << filaRey << ", " << colRey << ") está en jaque" << endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

const Casilla& tablero::at(int fila, int col) const {
    return grid[fila][col];
}

bool tablero::esJaqueMate(bool colorBlanco) {
    if (!estaEnJaque(colorBlanco))
        return false;

    for (int fila = 0; fila < 8; ++fila) {
        for (int col = 0; col < 8; ++col) {
            if (grid[fila][col].hayPieza()) {
                Pieza* pieza = grid[fila][col].getPieza();
                if (pieza->esBlanca() == colorBlanco) {
                    for (int f2 = 0; f2 < 8; ++f2) {
                        for (int c2 = 0; c2 < 8; ++c2) {
                            if (pieza->movimientoValido(fila, col, f2, c2, *this)) {
                                // Creamos copia del tablero
                                tablero copia = copiar();

                                // Referencia a la pieza dentro de la copia
                                Pieza* piezaCopia = copia.at(fila, col).getPieza();

                                // Simular el movimiento
                                Pieza* capturada = copia.at(f2, c2).getPieza();
                                copia.at(f2, c2).set(piezaCopia);
                                copia.at(fila, col).set(nullptr);
                                piezaCopia->setFila(f2);
                                piezaCopia->setColumna(c2);

                                // Verificar si sigue en jaque
                                if (!copia.estaEnJaque(colorBlanco))
                                    return false;
                            }
                        }
                    }
                }
            }
        }
    }

    return true; // Si ningún movimiento evita el jaque, es jaque mate
}


tablero tablero::copiar() const {
    tablero copia;
    for (int fila = 0; fila < 8; ++fila) {
        for (int col = 0; col < 8; ++col) {
            if (grid[fila][col].hayPieza()) {
                Pieza* original = grid[fila][col].getPieza();
                copia.grid[fila][col].set(original->clonar()); // OK
            }
            else {
                copia.grid[fila][col].set(nullptr);
            }
        }
    }
    return copia;
}
