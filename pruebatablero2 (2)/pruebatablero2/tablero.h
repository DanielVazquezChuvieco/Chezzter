#pragma once
#include "Casilla.h"
#include "Constantes.h"

class tablero
{
protected:
	static const int  filas = 8, columnas = 8; //Tablero est�ndar 8x8
	bool esBlanco;// atributo para determinar el color de la casilla

	//Atributos de tablero
	std::vector<std::vector<Casilla>> grid;  //Matriz 8x8 casillas

public:
	tablero();  //Constructor, incializa el tablero y coloca piezas
	void dibuja();  //Dibuja el tablero
	void colocapiezas();  //Posiciona las piezas en sus casillas iniciales
	Casilla& at(int fila, int columna);  //M�todo de acceso a las casillas espec�ficas,  SE VA A VER MUCHO M�S ADELANTE EN EL MOVIMIENTO DE LAS PIEZAS!!
	bool aplicarGravedadAccion();  //M�canica espec�fica del trabajo para que las piezas caigan a la posici�n m�s baja en su columna
	void aplicarGravedad();
	Pieza* encontrarRey(bool colorBlanco, int& filaRey, int& colRey) const;
	bool estaEnJaque(bool colorBlanco) const;
	const Casilla& at(int fila, int col) const;
	bool esJaqueMate(bool colorBlanco) ;
	tablero copiar() const;



};

