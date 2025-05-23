﻿#pragma once
#include "tablero.h"
#include "peon.h"
#include <string>
#include <iostream>
#include <cstring>

class juego        //1 Se encarga de guardar el estado del tablero y las piezas
	//2 Dibujar lo anteriormente mecionado
	//3 Gestionar el turno de cada jugador
	//4 Controla el movimiento de las piezas con el ratón arrastrando y soltando
{
public:
	tablero Tablero;   //Objeto que representa el tablero de ajedrez y todas sus piezas y casillas

	// Variables para movimiento de piezas por arrastre con ratón
	bool arrastrando = false;   //Indica si el usuario está arrastrando una pieza con el ratón
	int filaOrigen, colOrigen;  //Variables que se van a encargar de guardar la posición de donde se emmpezó a arrastrar la pieza
	Pieza* piezaArrastrada = nullptr;  //Apunta a la pieza que está siendo arrastrada

	//variables turnos
	bool turnoBlanco = true;

	// Para dibujar tablero y piezas;
	void dibuja();

	//Funciones arrastre
	void iniciarArrastre(int x, int y);  //Se llama cuando el usuario pulsa el ratón sobre una pieza para empezar a arrastrarla 
	void actualizarArrastre(int x, int y);  //Se llama mientras el usuario mueve el ratón con la pieza seleccionada
	void finalizarArrastre(int x, int y);  //Se llama cuando el usuario suelta la pieza en una casilla destino

	

};