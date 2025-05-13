#pragma once
#include "Casilla.h"
class tablero
{
	static const int  filas = 8, columnas = 8;
	bool esBlanco;// atributo para determinar el color de la casilla
	bool primera=true;
	//Atributos de tablero
	const int margenX = 100;
	const int margenY = 100;
	const int anchoPantalla = 800;
	const int largoPantalla = 800;
	int filaOrigen = -1, colOrigen = -1;
	Pieza* piezaSeleccionada = nullptr;

	std::vector<std::vector<Casilla>> grid;
public:
	//Casilla& at(int fila, int columna);
	tablero();
	void dibuja();
	void colocapiezas();
	void Tomar_Pieza(int fila, int col);
	void Soltar_Pieza(int fila, int col);
	Casilla& at(int fila, int columna);
	//friend class peon;
};

