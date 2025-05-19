#pragma once
#include <iostream>
#include <vector>
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Pieza.h"

class Casilla
{

	Pieza* pieza;   //Puntero a la pieza que está en la casilla
	const int tama�oCasilla = 75;   //tamaño de la casilla


public:
	Casilla() : pieza(nullptr) {};  //constructor, la casilla empieza vacía
	~Casilla() {};  //destructor
	void set(Pieza* p) { pieza = p; }  //Coloca una pieza en la casilla , puede ser nullptr para vaciarla
	int gettam() const { return tama�oCasilla; }  //Devuelve el tamaño de la casilla
	bool hayPieza() const { return pieza != nullptr; } //Devuelve true si hay una pieza en la casilla , false si está vacía
	Pieza* getPieza() const { return pieza; }  //Devuelve el puntero a la pieza o nullptr si está vacía

};
