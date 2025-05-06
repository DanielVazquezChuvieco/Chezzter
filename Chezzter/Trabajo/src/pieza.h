#pragma once
#include "freeglut.h"

enum ColorPieza { BLANCO, NEGRO };

class pieza
{
protected:
	int fila, columna;
	ColorPieza color;
public:
	pieza(int fila, int columna, ColorPieza color);  //Constructor
	void dibujaPieza(float TAMAÑO_CASILLA);

	int getFila();
	int getColumna();
	ColorPieza getColor();
	void setPosicion(int nuevaFila, int nuevaColumna);

};

