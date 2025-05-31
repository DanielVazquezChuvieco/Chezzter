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
#include "juego.h"  

using namespace std;


tablero::tablero() {
    grid.resize(filas, std::vector<Casilla>(columnas));  // crea un matriz de casillas llamada grid de 8x8 
    colocapiezas();
}

Casilla& tablero::at(int fila, int columna) {
    return grid[fila][columna];
}

const Casilla& tablero::at(int fila, int col) const {
    return grid[fila][col];
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



  
    for (int fila = 0; fila < filas; fila++) {
        for (int col = 0; col < columnas; col++) {
           
            esBlanco = (fila + col) % 2 == 0;
            if (esBlanco)
                glColor3f(0.2f, 0.2f, 0.6f); 
            else
                glColor3f(0.0f, 1.0f, 0.3f); 

            // Calculamos las coordenadas de cada cuadrado (esquina superior izquierda)
            int y = Constantes::margenX
                + col * Constantes::tamanoCasilla; 
            int x = Constantes::margenX
                + fila * Constantes::tamanoCasilla; 

            glBegin(GL_QUADS); // Iniciamos dibujo de un cuadrado
            glVertex2f(x, y);                           // esquina superior izquierda
            glVertex2f(x + Constantes::tamanoCasilla, y);             // esquina superior derecha
            glVertex2f(x + Constantes::tamanoCasilla, y + Constantes::tamanoCasilla); // esquina inferior derecha
            glVertex2f(x, y + Constantes::tamanoCasilla);             // esquina inferior izquierda
            glEnd(); 

        }
    }

    //Estas funciones se encargan de asignar numeros a las casillas
    for (int col = 0; col < columnas; col++) {
        char caracter = '0' + col;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glRasterPos2f(Constantes::margenX
            + Constantes::tamanoCasilla / 2 + col * Constantes::tamanoCasilla, 75); //Encargada de posicionar el caracter
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter); //Escribe en la tipologia elegida el caracter
    }
    for (int fila = 0; fila < filas; fila++) {
        char caracter = '0' + fila;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glRasterPos2f(75, Constantes::margenX
            + Constantes::tamanoCasilla / 2 + fila * Constantes::tamanoCasilla);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, caracter);
    }
    for (int fila = 0; fila < filas; fila++) {
        // Recorremos todas las columnas del tablero
        for (int col = 0; col < columnas; col++) {
            if (grid[fila][col].hayPieza()) {
                grid[fila][col].getPieza()->dibuja();  // Llamamos al metodo dibuja() de la pieza
               
            }
        }
    }
}

// AQUI USAMOS NO CONST (at)
//EL JODE VIDAS
/*
void tablero::colocapiezas() {
 

    at(6, 0).set(new Rey(6, 0, true));
    at(7, 0).set(new peon(7, 0, true));

    at(7, 3).set(new peon(7, 3, false));
    at(6, 3).set(new Rey(6, 3, false));
    at(7, 2).set(new peon(7, 2, false));


    at(6, 7).set(new Torre(6, 7, true));
    at(7, 7).set(new peon(7, 7, true));



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
    for (int col = 0; col < columnas; col++) { 
        for (int fila = filas - 2; fila >= 0; fila--) { // recorre todas las filas desde la penultima(no puede caer más si esta en la última)
            if (grid[fila][col].hayPieza()) { //verifica si hay pieza
                int nuevaFila = fila; 
                while (nuevaFila + 1 < filas && !grid[nuevaFila + 1][col].hayPieza()) {// recorre de la fila siguiente hasta que encuentre una pieza
                    nuevaFila++;
                }
                if (nuevaFila != fila) { // si la nueva fila es distinta de la fila inicial
                    Pieza* pieza = grid[fila][col].getPieza();// cogemos la pieza original
                    grid[nuevaFila][col].set(pieza);//la colocamos en la nueva fila
                    grid[fila][col].set(nullptr);//liberamos la anterior
                    pieza->setFila(nuevaFila);//actualiza posicíon interna
                    pieza->setColumna(col);
                }
            }
        }
    }
}
bool tablero::aplicarGravedadAccion() { 
    bool huboMovimiento = false;
    for (int col = 0; col < columnas; col++) {  //Recorremos todas las columnas del tablero
        for (int fila = filas - 2; fila >= 0; fila--) {  //Recorremos las filas desde la penúltima hasta la primera
            if (grid[fila][col].hayPieza() && !grid[fila + 1][col].hayPieza()) {  // Si hay una pieza en la casilla actual y la casilla de abajo está vacía
                Pieza* pieza = grid[fila][col].getPieza();  //Obtenemos la pieza de la casilla actual
                grid[fila + 1][col].set(pieza); //Movemos la pieza a la casilla de abajo
                grid[fila][col].set(nullptr);  //Borramos la referencia de la casilla actual
                pieza->setFila(fila + 1);  //Actualizamos la fila de la pieza
                pieza->setColumna(col); //La columna sigue siendo la misma
                pieza->setPosicionGrafica();  //Actualizamos posición gráfica
                huboMovimiento = true;  //Indicamos que hubo al menos un movimiento
            }
        }
    }
    return huboMovimiento;   //Si hubo movimiento devuelve true
}


Pieza* tablero::encontrarRey(bool colorBlanco, int& filaRey, int& colRey) const {
    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
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

    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            if (grid[fila][col].hayPieza()) {
                Pieza* pieza = grid[fila][col].getPieza();
                if (pieza->esBlanca() != colorBlanco) {  // enemigo
                    if (pieza->movimientoValido(fila, col, filaRey, colRey, *this)) { //this hace referncia al propio objeto del tablero
                        return true;
                    }
                }
            }
        }
    }

    return false;
}


bool tablero::esJaqueMate(bool colorBlanco) {
    if (!estaEnJaque(colorBlanco))
        return false;

    // Probar todos los movimientos posibles de las piezas del jugador
    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8;col++) {
            if (grid[fila][col].hayPieza()) {
                Pieza* pieza = grid[fila][col].getPieza();
                if (pieza->esBlanca() == colorBlanco) {
                    for (int f2 = 0; f2 < 8; f2++) {
                        for (int c2 = 0; c2 < 8; c2++) {
                            tablero copia = this->copiar();  // crea una copia de ESE tablero (copiame a mi)

                            Pieza* pCopia = copia.at(fila, col).getPieza(); // pieza de la copia
                            
                                if (pCopia->movimientoValido(fila, col, f2, c2, copia)) {
                                    // Simular movimiento y comprobar jaque
                                    copia.at(f2, c2).set(pCopia);
                                    copia.at(fila, col).set(nullptr);
                                    pCopia->setFila(f2);
                                    pCopia->setColumna(c2);

                                    copia.aplicarGravedad();

                                    if (!copia.estaEnJaque(colorBlanco)) {
                                        return false; // Existe un movimiento válido que salva al rey
                                    }
                                }
                            
                        }
                    }
                }
            }
        }
    }

    
    return true;  // Ningún movimiento salva al rey
}

void tablero::limpiar() {
    for (int fila = 0; fila < filas;fila++) {
        for (int col = 0; col < columnas; col++) {
            delete grid[fila][col].getPieza();   // Elimina pieza
            grid[fila][col].set(nullptr);        
        }
    }
}



tablero tablero::copiar() const {
    tablero copia;
    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            if (grid[fila][col].hayPieza()) {
                Pieza* original = grid[fila][col].getPieza();
                copia.grid[fila][col].set(original->clonar()); 
            }
            else {
                copia.grid[fila][col].set(nullptr);
            }
        }
    }
    return copia;
}
