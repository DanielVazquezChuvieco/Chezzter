#include "tablero.h"
#include "pieza.h"
#include "peon.h"

class Mundo
{
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	double x_ojo;
	double y_ojo;
	double z_ojo; 

	tablero TableroAjedrez;
};
