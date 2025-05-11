#include "Casilla.h"

void Casilla::borrar(Pieza* p) {
	delete pieza;
	pieza = nullptr;
}