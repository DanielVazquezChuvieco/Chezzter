#pragma once
#include "tablero.h"
#include "peon.h"
#include <string>
#include <iostream>
#include <cstring>
#include "Coordinador.h"

class juego      
{
	tablero Tablero;   //Objeto que representa el tablero de ajedrez y todas sus piezas y casillas
	Coordinador coordinador;
	// Variables para movimiento de piezas por arrastre con ratón
	bool arrastrando = false;   //Indica si el usuario está arrastrando una pieza con el ratón
	int filaOrigen, colOrigen;  //Variables que se van a encargar de guardar la posición de donde se emmpezó a arrastrar la pieza
	Pieza* piezaArrastrada = nullptr;  //Apunta a la pieza que está siendo arrastrada
	bool turnoBlanco = true; //variables turnos

public:
	
	void dibuja();
	//Funciones arrastre
	void iniciarArrastre(int x, int y);  //Se llama cuando el usuario pulsa el ratón sobre una pieza para empezar a arrastrarla 
	void actualizarArrastre(int x, int y);  //Se llama mientras el usuario mueve el ratón con la pieza seleccionada
	void finalizarArrastre(int x, int y);  //Se llama cuando el usuario suelta la pieza en una casilla destino
	bool simularMovimientoConGravedadYVerificar(int filaOrigen, int colOrigen, int filaDestino, int colDestino); //simular el mov con gravedad y verificar
	void postGravedad(); // verifica jaque y jaque mate POST animacion
	tablero& getTablero() { return Tablero; }  //Te devuelve el tablero para la animación de gravedad
	void reiniciarJuego(); // coloca de nuevo las piezas y resetea el turno
	
	
};