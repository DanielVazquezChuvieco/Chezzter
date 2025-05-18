#pragma once
#include "tablero.h"
#include "peon.h"
#include <string>
#include <iostream>
#include <cstring>

class juego
{
public:
	tablero Tablero;
	int filaOrigen = 0;
	int colOrigen = 0;
	bool esperandoSegundoClick = false;
	Pieza* piezaSeleccionada = nullptr;
	std::string turnoActual = "BLANCO"; // ← ahora usamos string

	void dibuja(); // Para dibujar tablero y piezas;
	void moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino);
	void clickRaton(int x, int y);

	std::string obtenerTurnoActual() const;
	void cambiarTurno();
	bool esTurnoDe(const std::string& color) const;

};