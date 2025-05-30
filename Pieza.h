#pragma once
#include "ETSIDI.h"
#include "Constantes.h"
#include <string>

class tablero; //Se pone la clase tablero para pasar por referencia movimientoValido() y verificar la ocupación de casillas e implementar reglas
class Pieza  //Clase base con herencia en peon,torre,caballo,alfil,reina,rey
{
protected:
    int fila;  //Fila del tsblero 0-7 
    int columna;  //Columna tablero 0-7
    bool esBlancoPieza;   //True = piezablanca   Flase = piezanegra
 


public:
    void setFila(int f) { fila = f; }  //Actualiza la fila
    void setColumna(int c) { columna = c; }  //Actualiza la columna
    Pieza(int filaIni, int columnaIni, bool blanca) :fila(filaIni), columna(columnaIni), esBlancoPieza(blanca), sprite(nullptr) {}  //constructor, inicializa posición y color
    ETSIDI::SpriteSequence* sprite;  //Objeto gráfico para la ppieza

    virtual ~Pieza() { delete sprite; }  //Destructor virtual para herencia
    bool esBlanca() const { return esBlancoPieza; }  // Obtener color
    virtual void dibuja();  //Dibuja la pieza, implementado en clases derivadas
    void setPosicionGrafica();  //Posicionamiento gráfico de la pieza

    virtual bool movimientoValido(int filaOrigen, int colOrigen, int filaDestino, int colDestino, const tablero& Tablero)  = 0;  //Método para obbtener el movimiento válido de las piezas

    void setPosicionGraficaPixel(int x, int y); // Nuevo método para arrastrar piezas, posiciona las piezas según las coordenadas en pantalla
       
    virtual std::string nombre() const = 0;

    virtual bool esRey() const { return false; }

    virtual Pieza* clonar() const = 0;  

protected:
    bool intentaComerSuPropioRey(int filaDestino, int colDestino, const tablero& Tablero) const;
};