#pragma once
#include "ETSIDI.h"

class peon {
private:
    int fila;
    int columna;
    bool esBlanco;
    ETSIDI::SpriteSequence* sprite; //Defino a partir de la libreria ETSIDI igual que en la P5
            //aunque nos toca usar un puntero ya que no se puede dejar un spirit sin pasarle parametros
    //y es lo que estaba dando error ya que, hasta los ifs del constructor no se asignaba la imagen

public:
    peon(int filaIni, int columnaIni, bool blanca); //Constructor 
    void dibuja();
};



