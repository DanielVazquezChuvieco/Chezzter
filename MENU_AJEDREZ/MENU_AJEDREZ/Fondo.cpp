
#include "Fondo.h"
#include "ETSIDI.h"
#include <GL/freeglut.h>

void Fondo::dibujar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // limpia pantalla

    // HABILITA TEXTURA Y PINTA LA IMAGEN
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_astronauta.png").id);

    glBegin(GL_QUADS); // o GL_POLYGON si usas eso
    glColor3f(1, 1, 1); // blanco para no teñir la textura
    glTexCoord2f(0, 1); glVertex2f(-10, 0);
    glTexCoord2f(1, 1); glVertex2f(10, 0);
    glTexCoord2f(1, 0); glVertex2f(10, 15);
    glTexCoord2f(0, 0); glVertex2f(-10, 15);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // DIBUJA EL TEXTO U OTRAS COSAS DESPUÉS DEL FONDO

}
