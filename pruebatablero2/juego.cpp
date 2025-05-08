#include "juego.h"
#include "freeglut.h"
#include "peon.h"

void juego::dibuja() {
	Tablero.dibuja();

	peon1.dibuja();
	peon2.dibuja();
	peon3.dibuja();
	peon4.dibuja();
	peon5.dibuja();
	peon6.dibuja();
	peon7.dibuja();
	peon8.dibuja();

	peon01.dibuja();
	peon02.dibuja();
	peon03.dibuja();
	peon04.dibuja();
	peon05.dibuja();
	peon06.dibuja();
	peon07.dibuja();
	peon08.dibuja();


	//iran todos los dibujas
}

void juego::inicia() {

}
