#include "Tablero.h"
using namespace std;

Tablero::Tablero() {
	grid.resize(filas, vector<Casilla>(columnas));
	colocapiezas();
}
void Tablero::construir() {
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cout << grid[i][j].getPiece() << " ";
		}
		cout << endl;
	}
}

Casilla& Tablero::at(int fila, int columna) {
	return grid[fila][columna];
}

void Tablero::colocapiezas() {
	for (int i = 0; i < 8; ++i) { // colocar peones
		at(1, i).set('p');
		at(6, i).set('P');
	}
	// torres 
	at(7, 0).set('R'); at(7, 7).set('R');
	at(0, 0).set('r'); at(0, 7).set('r');
	//alfiles
	at(7, 2).set('A'); at(7, 5).set('A');
	at(0, 2).set('a'); at(0, 5).set('a');
	//Caballos
	at(7, 1).set('C'); at(7, 6).set('C');
	at(0, 1).set('c'); at(0, 6).set('c');
	//Reyes
	at(7, 3).set('K');
	at(0, 3).set('k');
	//Reinas
	at(7, 4).set('Q');
	at(0, 4).set('q');
}