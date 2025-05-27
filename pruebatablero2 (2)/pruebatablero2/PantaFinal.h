#include "freeglut.h"
#pragma once
#include "ETSIDI.h"


enum ResultadoPartida {
    EN_CURSO,
    GANA_BLANCAS,
    GANA_NEGRAS
};

class PantaFinal {
private:
    ResultadoPartida resultado = EN_CURSO;
   // ResultadoPartida resultado = GANA_BLANCAS;


public:
    void setResultado(ResultadoPartida r);
    ResultadoPartida getResultado() const;
    void dibujar();
};
