#include "juego.h"
#include "freeglut.h"
#include "peon.h"


void juego::dibuja() {
	Tablero.dibuja();

	//iran todos los dibujas
}

void juego::clickRaton(int x, int y) {
	int fila = (y - 100) / 75;
	int col = (x - 100) / 75;

	if (!esperandoSegundoClick) {
		if (Tablero.at(fila, col).hayPieza()) {
			filaOrigen = fila;
			colOrigen = col;
		}
		esperandoSegundoClick = true;
	}
	else {
		Casilla& origen = Tablero.at(filaOrigen, colOrigen);
		Casilla& destino = Tablero.at(fila, col);

		if (origen.hayPieza()) {
			destino.set(origen.getPieza()); // mover puntero
			origen.set(nullptr);            // borrar en origen
		}
	}
	

	esperandoSegundoClick = false;
	glutPostRedisplay();  // Fuerza redibujado

}

