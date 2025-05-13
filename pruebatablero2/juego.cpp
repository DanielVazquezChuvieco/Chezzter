#include "juego.h"
#include "freeglut.h"
#include "peon.h"
#include<iostream>

using namespace std;

void juego::dibuja() {
	Tablero.dibuja();

	//iran todos los dibujas
}

void juego::clickRaton(int x, int y) {
    int fila = (y - 100) / 75;
    int col = (x - 100) / 75;

    cout << "Click en: (" << fila << ", " << col << ")" << endl;
    cout << "Estado esperandoSegundoClick: " << esperandoSegundoClick << endl;

    if (!esperandoSegundoClick) {
        if (fila >= 0 && fila < 8 && col >= 0 && col < 8) {
            if (Tablero.at(fila, col).hayPieza()) {
                filaOrigen = fila;
                colOrigen = col;
                cout << "Hay pieza en origen" << endl;
                esperandoSegundoClick = true;
            }
            else {
                cout << "No hay pieza en (" << fila << ", " << col << ")" << endl;
            }
        }
        else {
            cout << "Click fuera del tablero en primer clic" << endl;
        }
    }
    else {
        cout << "Entrando al segundo click (Destinoo)" << endl;

        if (filaOrigen >= 0 && filaOrigen < 8 && colOrigen >= 0 && colOrigen < 8 &&
            fila >= 0 && fila < 8 && col >= 0 && col < 8) {

            cout << "Verificando casilla origen: (" << filaOrigen << ", " << colOrigen << ")" << endl;

            Casilla& origen = Tablero.at(filaOrigen, colOrigen);
            Casilla& destino = Tablero.at(fila, col);

            if (origen.hayPieza()) {
                cout << "Origen tiene pieza" << endl;

                Pieza* pieza = origen.getPieza();
                if (pieza) {
                    cout << "Puntero a pieza válido" << endl;

                    destino.set(pieza);
                    origen.set(nullptr);

                    pieza->setFila(fila);
                    pieza->setColumna(col);
                    pieza->setPosicionGrafica();

                    cout << "Movimiento realizado a (" << fila << ", " << col << ")" << endl;
                }
                else {
                    cout << "Puntero a pieza es NULL" << endl;
                }
            }
            else {
                cout << "Origen NO tiene pieza (aunque debería)" << endl;
            }
        }
        else {
            cout << "Coordenadas fuera de rango en segundo clic" << endl;
        }

        esperandoSegundoClick = false;
        glutPostRedisplay();
    }
}
