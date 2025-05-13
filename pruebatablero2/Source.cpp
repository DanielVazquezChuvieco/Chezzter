#include "freeglut.h"
#include "tablero.h"
#include "juego.h"

juego Juego;

void onDraw(); // esta función será llamada para dibujar
void onMouseClick(int button, int state, int x, int y);

// Función principal del programa
int main(int argc, char** argv) {
    // Inicializamos GLUT (sistema de ventanas)
    glutInit(&argc, argv);

    // Usamos doble buffer y modo RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Establecemos el tamaño inicial de la ventana
    glutInitWindowSize(800, 800);

    // Creamos la ventana con el título deseado
    glutCreateWindow("CHEZZTER");

    // Equivalente en 2D a gluPerspective LAB
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 800, 0);
    glViewport(0, 0, 800, 800);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Funciones de dibujo e interacción
    glutDisplayFunc(onDraw);
    glutMouseFunc(onMouseClick);

    // Bucle principal de GLUT
    glutMainLoop();

    return 0;
}

void onDraw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    Juego.dibuja();
    glutSwapBuffers();
}

void onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Juego.clickRaton(x, y);
    }
}
