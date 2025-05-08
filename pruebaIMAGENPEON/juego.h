#pragma once
#include "tablero.h"
#include "peon.h"

class juego
{
public:
	tablero Tablero;
	peon peon1{ 6, 0, true };
	peon peon2{ 6, 1, true };
	peon peon3{ 6, 2, true };
	peon peon4{ 6, 3, true };
	peon peon5{ 6, 4, true };
	peon peon6{ 6, 5, true };
	peon peon7{ 6, 6, true };
	peon peon8{ 6, 7, true };

	peon peon01{ 1, 0, false }; 
	peon peon02{ 1, 1, false };
	peon peon03{ 1, 2, false };
	peon peon04{ 1, 3, false };
	peon peon05{ 1, 4, false };
	peon peon06{ 1, 5, false };
	peon peon07{ 1, 6, false };
	peon peon08{ 1, 7, false };

	//definimos las piezas y todo

	void dibuja();
	//definimos las funciones genericas de todo
	void inicia();
};

