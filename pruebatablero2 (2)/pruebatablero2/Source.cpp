#include "freeglut.h"
#include "tablero.h"
#include "juego.h"

juego Juego;

void onDraw(); // esta función será llamada para dibujar
void onMouseClick(int button, int state, int x, int y);
void onMouseDrag(int x, int y);  //Nueva función de arrastre

void timerGravedad(int value);  //Temporizador para la animación de gravedad

//void timerGravedad(int value);  //Temporizador para la animación de gravedad


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
    glutMotionFunc(onMouseDrag);  //Movimiento con botón pulsado

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
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            Juego.iniciarArrastre(x, y);
        }
        else if (state == GLUT_UP) {
            Juego.finalizarArrastre(x, y);

            glutTimerFunc(300, timerGravedad, 0);

        }
    }
}

void onMouseDrag(int x, int y) {
    Juego.actualizarArrastre(x, y);
}

void timerGravedad(int value) {

    if (Juego.getTablero().aplicarGravedadAccion()) {
        glutPostRedisplay();
        glutTimerFunc(300, timerGravedad, 0);  // animación continua
    }
    else {
        Juego.postGravedad();  // cuando termina la gravedad
        glutPostRedisplay();
    }
}

        