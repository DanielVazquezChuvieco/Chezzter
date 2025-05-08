#pragma once

class tablero
{
	//Atributos de tablero
	int filas = 8;
	int columnas = 8;
	int tamañoCasilla = 75;
	int margenX = 100;
	int margenY = 100;
	int anchoPantalla = 800;
	int largoPantalla = 800 ;

public: 
	void dibuja();

	//friend class peon;
};

