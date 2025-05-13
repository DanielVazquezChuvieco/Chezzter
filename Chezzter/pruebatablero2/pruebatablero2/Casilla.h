#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Pieza.h"

class Casilla
{

	Pieza* pieza;
	const int tama�oCasilla = 75;


public:
	Casilla() : pieza(nullptr) {};
	~Casilla() {};
	void set(Pieza* p) { pieza = p; }
	int gettam() const { return tama�oCasilla; }
	bool hayPieza() const { return pieza != nullptr; }
	Pieza* getPieza() const { return pieza; }
	//Pieza getPiece(Pieza*p) const { return  }

};
