#include "pieza.h"

pieza::pieza(int fila, int columna, ColorPieza color): fila(fila), columna(columna), color(color) {}  //Inicializa constructor

void pieza::dibujaPieza(float tam_casilla)
{
    float x = columna * tam_casilla + tam_casilla / 2.0f;
    float y = fila * tam_casilla + tam_casilla / 2.0f;

    if (color == BLANCO)
        glColor3f(255, 255, 255);
    else
        glColor3f(0, 0, 0);

    glPushMatrix();
    glTranslatef(x, y, 0);
    glutSolidSphere(tam_casilla / 3.0f, 20, 20);
    glPopMatrix();
}

int pieza::getFila() 
{
    return fila;
}

int pieza::getColumna()
{
    return columna;
}

ColorPieza pieza::getColor()
{
    return color;
}

void pieza::setPosicion(int nuevaFila, int nuevaColumna) 
{
    fila = nuevaFila;
    columna = nuevaColumna;
}