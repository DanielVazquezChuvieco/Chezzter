#pragma once

enum Estado {
    MENU=0,
    JUEGO,
    INSTRUCCIONES,
    CONTROLES,
    GANA_BLANCAS,
    GANA_NEGRAS
};

class Coordinador
{
private:
   
    Estado estado = MENU;

public:
    void setResultado(Estado r);
    void tecla(unsigned char tecla);
    void dibujapantallamenu();
    Estado getEstado();


};

