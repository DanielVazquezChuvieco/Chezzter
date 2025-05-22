#pragma once
#include "Casilla.h"
class tablero
{
	static const int  filas = 8, columnas = 8; //Tablero est�ndar 8x8
	bool esBlanco;// atributo para determinar el color de la casilla

	//Atributos de tablero
	const int margenX = 100;
	const int margenY = 100;
	const int anchoPantalla = 800;
	const int largoPantalla = 800;
	std::vector<std::vector<Casilla>> grid;  //Matriz 8x8 casillas

public:
	tablero();  //Constructor, incializa el tablero y coloca piezas
	void dibuja();  //Dibuja el tablero
	void colocapiezas();  //Posiciona las piezas en sus casillas iniciales
	Casilla& at(int fila, int columna);  //M�todo de acceso a las casillas espec�ficas,  SE VA A VER MUCHO M�S ADELANTE EN EL MOVIMIENTO DE LAS PIEZAS!!
	void aplicarGravedad();  //M�canica espec�fica del trabajo para que las piezas caigan a la posici�n m�s baja en su columna
	Pieza* encontrarRey(const std::string& color, int& filaRey, int& colRey) const;
	bool estaEnJaque(const std::string& color) const;
	const Casilla& at(int fila, int col) const;


};

