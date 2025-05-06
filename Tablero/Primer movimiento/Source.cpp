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
	
	void borrar() {
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
};

void main() {
	tablero tab;
	//vector <int> input(2);
	int input1, input2,output1,output2;
	while (true) {
		tab.construir();
		cout << "Escribe tu movimiento"<<'\n'<<"0 para terminar"<<endl;
		/*for (auto n : input) {
			cin >> n;
		}*/
		cin >> input1 >> input2>>output1>>output2;

		if (input1 == 0) {
			break;
		}
		
		//vector <int> from{ input1,input2 };
		//vector <int> to  { output1,output2 };

		casilla& de = tab.at(input1, input2);
		casilla& a = tab.at(output1, output2);
		if (de.getPiece() == '.') {
			std::cout << "No hay pieza en la casilla de origen." << std::endl;
			continue;
		}
		a.set(de.getPiece());
		de.borrar();
		
	}
	std::cout << "¡Hasta luego!" << std::endl;
	
}