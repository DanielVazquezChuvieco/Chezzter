#include "Mundo.h"
#include "freeglut.h"
#include <cmath>

void Mundo::rotarOjo()
{
	double dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	double ang=atan2(z_ojo,x_ojo);
	ang+=0.05;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	TableroAjedrez.dibujaTablero();
	
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=4;
	y_ojo=4;
	z_ojo=15;
}

void Mundo::tecla(unsigned char key)
{

}
