#pragma once
#include "tablero.h"
#include "peon.h"

class juego
{
public:
	tablero Tablero;
	int filaOrigen = -1;
	int colOrigen = -1;
	bool esperandoSegundoClick = false;

	
	void dibuja(); // Para dibujar tablero y piezas;
	void clickRaton(int x, int y);


};

