#pragma once
#include "tablero.h"
#include "peon.h"

class juego
{
public:
	tablero Tablero;
	int filaOrigen = 0;
	int colOrigen = 0;
	bool esperandoSegundoClick = false;
	Pieza* piezaSeleccionada = nullptr;


	void dibuja(); // Para dibujar tablero y piezas;
	void moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino);
	void clickRaton(int x, int y);


};