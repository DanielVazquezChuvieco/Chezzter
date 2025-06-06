#include "freeglut.h"
#include "tablero.h"
#include "juego.h"
#include "Coordinador.h"

juego Juegos;
Coordinador coordinador;
void onDraw(); // esta funci�n ser� llamada para dibujar
void onMouseClick(int button, int state, int x, int y);
void onMouseDrag(int x, int y);  //Nueva funci�n de arrastre
void OnKeyboardDown(unsigned char key, int x_t, int y_t);
void timerGravedad(int value);  //Temporizador para la animaci�n de gravedad
void timerGravedad(int value);  //Temporizador para la animaci�n de gravedad


// Funci�n principal del programa
int main(int argc, char** argv) {
    // Inicializamos GLUT (sistema de ventanas)
    glutInit(&argc, argv);

    // Usamos doble buffer y modo RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Establecemos el tama�o inicial de la ventana
    glutInitWindowSize(800, 800);

    // Creamos la ventana con el t�tulo deseado
    glutCreateWindow("CHEZZTER");

    // Equivalente en 2D a gluPerspective LAB
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 800, 0);
    glViewport(0, 0, 800, 800);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Funciones de dibujo e interacci�n
    glutDisplayFunc(onDraw);
    glutMouseFunc(onMouseClick);
    glutMotionFunc(onMouseDrag);  //Movimiento con bot�n pulsado
    glutKeyboardFunc(OnKeyboardDown);
    // Bucle principal de GLUT

   // ETSIDI::play("sonidos/chuvi.mp3");
    glutMainLoop();

    return 0;
}

void onDraw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    coordinador.dibujapantallamenu();
    if (coordinador.getEstado() == JUEGO) {
        Juegos.dibuja();
    }
    glutSwapBuffers();
}

void onMouseClick(int button, int state, int x, int y) {
    if (coordinador.getEstado() == JUEGO) {
        if (button == GLUT_LEFT_BUTTON) {
            if (state == GLUT_DOWN) {
                Juegos.iniciarArrastre(x, y);
            }
            else if (state == GLUT_UP) {
                Juegos.finalizarArrastre(x, y);

                glutTimerFunc(300, timerGravedad, 0);

            }
        }
        glutPostRedisplay();
    }
}

void onMouseDrag(int x, int y) {
    if (coordinador.getEstado() == JUEGO) {
        Juegos.actualizarArrastre(x, y);

        glutPostRedisplay();
    }
}

void timerGravedad(int value) {

    if (Juegos.getTablero().aplicarGravedadAccion()) {
        glutPostRedisplay();
        glutTimerFunc(300, timerGravedad, 0);
    }
    else {
        Juegos.postGravedad();
        glutPostRedisplay();
    }

}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) {

    coordinador.tecla(key);
    glutPostRedisplay();
}
