#pragma once
class peon
{
	float r = 20;
	int fila;
	int columna;
	bool esBlanco;


public:
	void dibuja();

	peon(int filaIni, int columnaIni, bool blanca) {
		fila = filaIni;
		columna = columnaIni;
		esBlanco = blanca;
	}
};

