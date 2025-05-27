#include "PantaFinal.h"
#include <iostream>
#include "ETSIDI.h"
using namespace std;

void PantaFinal::setResultado(ResultadoPartida r) {
    resultado = r;
}

ResultadoPartida PantaFinal::getResultado() const {
    return resultado;
}

void PantaFinal::dibujar() {


    if (resultado == EN_CURSO) {

        return;
    }
    glDisable(GL_LIGHTING);

    // Fondo según resultado
    if (resultado == GANA_BLANCAS) {
        ETSIDI::play("sonidos/astro.mp3");

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Astro_gana.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); 
        glTexCoord2d(1, 0); glVertex2f(800, 0); 
        glTexCoord2d(1, 1); glVertex2f(800, 800); 
        glTexCoord2d(0, 1); glVertex2f(0, 800);
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
    else {
        ETSIDI::play("sonidos/alien.mp3");

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Alien_gana.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); 
        glTexCoord2d(1, 0); glVertex2f(800, 0); 
        glTexCoord2d(1, 1); glVertex2f(800, 800); 
        glTexCoord2d(0, 1); glVertex2f(0, 800); 
        glEnd();

        // glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    }
}



