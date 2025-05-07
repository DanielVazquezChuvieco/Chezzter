#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
class Casilla
{
public:
	char pieza;
	Casilla() :pieza('.') {};
	void set(char p) { pieza = p; }

	void borrar(char p) { pieza = '.'; }

	char getPiece() const { return pieza; }
};

