#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class casilla {

public:
	char pieza; // publico;

	
	casilla() :pieza('.'){};

	void set(char p) {
		pieza = p;
	 }
	
	void borrar(char p) {
		pieza = '.';
	}

	char getPiece() const {
		return pieza;
	}
};

class tablero {
	static const int size = 8;
	int  filas=8, columnas=8;
	vector <vector<casilla>> grid; // vector de vectores casilla, es un vector de tipo casilla, es decir accedemos a los atributos de casilla
	
public:
    tablero() {
	    grid.resize(size, vector<casilla>(size)); 
		colocapiezas();
    }
	void construir() {
		for (int i = 0; i < filas; ++i) {
			for (int j = 0; j < columnas; ++j) {
				cout << grid[i][j].getPiece()<<" ";
			}
			cout << endl;
		}
	}
	casilla& at(int fila, int columna) { // manera de colocar las casillas con coordenandas numericas
		return grid[fila][columna];
	}

	//casilla& at();

private :
	void colocapiezas() {
		for (int i = 0; i < 8; ++i) { // colocar peones
			at(1, i).set('P');
			at(6, i).set('P');
		}
		// torres 
		at(7, 0).set('R'); at(7, 7).set('R');
		at(0, 0).set('r'); at(0, 7).set('r');
		//alfiles

	}
};

void main() {
	tablero tab;

	tab.construir();
}