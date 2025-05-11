#pragma once
#include "Casilla.h"
class tablero
{
	static const int  filas = 8, columnas = 8;
	bool esBlanco;// atributo para determinar el color de la casilla
	//Atributos de tablero
	const int margenX = 100;
	const int margenY = 100;
	const int anchoPantalla = 800;
	const int largoPantalla = 800 ;
	std::vector<std::vector<Casilla>> grid;
public: 
	//Casilla& at(int fila, int columna);
	tablero();
	void dibuja();
	void colocapiezas();
	Casilla& at(int fila, int columna);
	//friend class peon;
};

