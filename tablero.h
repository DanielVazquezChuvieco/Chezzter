#pragma once
#include "Casilla.h"
#include "Constantes.h"

class tablero
{
protected:
	static const int  filas = 8, columnas = 8; //Tablero estándar 8x8
	bool esBlanco;// atributo para determinar el color de la casilla
	std::vector<std::vector<Casilla>> grid;  //Matriz 8x8 casillas

public:
	tablero();  //Constructor, incializa el tablero y coloca piezas
	void dibuja();  //Dibuja el tablero
	void colocapiezas();  //Posiciona las piezas en sus casillas iniciales
	Casilla& at(int fila, int columna);  
	void aplicarGravedad();  //Mécanica específica del trabajo para que las piezas caigan a la posición más baja en su columna
	bool aplicarGravedadAccion(); // animación de gravedad
	Pieza* encontrarRey(bool colorBlanco, int& filaRey, int& colRey) const; // emtodo para encontrar al rey
	bool estaEnJaque(bool colorBlanco) const;  // metodo para ver si esta en jaque
	const Casilla& at(int fila, int col) const;	
	bool esJaqueMate(bool colorBlanco) ; // metodo para ver si esta en jaque mate
	tablero copiar() const; // metodo para copiar el tablero y simular
	void limpiar(); //metodo para limpiar las piezas y poder reiniciar la partida



};

