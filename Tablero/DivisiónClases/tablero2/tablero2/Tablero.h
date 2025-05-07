#pragma once

#include "Casilla.h"

using namespace std;
class Tablero
{
	static const int  filas = 8, columnas = 8;
	vector <vector<Casilla>> grid;
public:
	void construir();
	Casilla& at(int fila, int columna);
	Tablero();
private:
	void colocapiezas();
};

