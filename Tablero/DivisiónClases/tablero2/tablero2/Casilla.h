#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Pieza.h"
class Casilla
{
public:
	Pieza *pieza;

	Casilla() : pieza(nullptr) {};

	//Casilla() :pieza('.') {};
	
	void set(Pieza*p) { pieza = p; }

	void borrar(Pieza* p);

	char getPiece() const { return pieza; }
};

