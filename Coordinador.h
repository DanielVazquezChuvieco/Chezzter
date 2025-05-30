#pragma once

enum Estado {
    MENU,
    JUEGO,
    INSTRUCCIONES,
    CONTROLES
};

class Coordinador
{
private:
    Estado estado = MENU;

public:
    void tecla(unsigned char tecla);
    void dibujapantallamenu();
    Estado getEstado();
    

};

