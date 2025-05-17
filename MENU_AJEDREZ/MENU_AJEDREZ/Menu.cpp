#include <GL/freeglut.h>
#include "Fondo.h"
#include "Texto.h"
#include "Musica.h"

void OnDraw() {
    glClear(GL_COLOR_BUFFER_BIT);
    Fondo::dibujar();
    Texto::dibujar();
    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Menú Ajedrez");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, 0, 15);
    glMatrixMode(GL_MODELVIEW);



    Musica::reproducir();


    glutDisplayFunc(OnDraw);
    glutMainLoop();

    return 0;
}
