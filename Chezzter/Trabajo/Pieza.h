#pragma once
class Pieza
{
	char pieza;
	bool color;
public:
	Pieza(char pieza, bool color) : pieza(pieza), color(color) {}
	virtual ~Pieza()=default;
	virtual bool movimientovalido(int filaO, int columnaO, int filaD, int columnaD);
	char getpieza
};

