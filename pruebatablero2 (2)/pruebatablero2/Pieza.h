#pragma once
#include "ETSIDI.h"
#include <string>

class tablero; //Se pone la clase tablero para pasar por referencia movimientoValido() y verificar la ocupación de casillas e implementar reglas

class Pieza  //Clase base con herencia en peon,torre,caballo,alfil,reina,rey
{
protected:
    int fila;  //Fila del tsblero 0-7 
    int columna;  //Columna tablero 0-7
    bool esBlancoPieza;   //True = piezablanca   Flase = piezanegra
    static const int tama�oCasilla = 75;  //Tamaño visual de la casilla
    static const int margenX = 100;   //Margen horizontal del tablero
    static const int margenY = 100;  //Margen vertical del tablero


public:
    void setFila(int f) { fila = f; }  //Actualiza la fila
    void setColumna(int c) { columna = c; }  //Actualiza la columna
    Pieza(int filaIni, int columnaIni, bool blanca) :fila(filaIni), columna(columnaIni), esBlancoPieza(blanca), sprite(nullptr) {}  //constructor, inicializa posición y color
    ETSIDI::SpriteSequence* sprite;  //Objeto gráfico para la ppieza

    virtual ~Pieza() { delete sprite; }  //Destructor virtual para herencia
    bool getcolor() const { return esBlancoPieza; }  // Obtener color
    virtual void dibuja();  //Dibuja la pieza, implementado en clases derivadas
    void setPosicionGrafica();  //Posicionamiento gráfico de la pieza

    virtual bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, tablero& Tablero) = 0;  //Método para obbtener el movimiento válido de las piezas

    void setPosicionGraficaPixel(int x, int y) { // Nuevo método para arrastrar piezas, posiciona las piezas según las coordenadas en pantalla
        sprite->setPos(x - 25, y - 25);
        sprite->setCenter(0.5f, 0.5f);  //Centra el sprite
        sprite->setSize(50, 50);  //Tamaño estándar
    }

    std::string obtenerColor() const {   //Lógica de turnos
        return esBlancoPieza ? "BLANCO" : "NEGRO";
    }
};