#include "freeglut.h"
#include "tablero.h"
#include "juego.h"

juego Juego;


void onDraw(); //esta funcion sera llamada para dibujar
void onMouseClick(int button, int state, int x, int y);
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

    //Equivalente en 2D a gluPerspective LAB
    glMatrixMode(GL_PROJECTION); // Cambiamos al modo de proyecci�n (para ajustar la c�mara)
    glLoadIdentity();            // Cargamos una matriz de identidad (sin transformaciones)
    // Usamos una proyecci�n 2D simple, con origen en la esquina superior izquierda
    gluOrtho2D(0, 800, 800, 0);
    glViewport(0, 0, 800, 800); //ajusto lo que se ve entre (0,0) abajo izq y (800,800) arriba dcha.

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // Le decimos a GLUT qu� funci�n usar para dibujar
    glutDisplayFunc(onDraw);

    glutMouseFunc(onMouseClick);


    // Entramos en el bucle principal de GLUT (no vuelve nunca)
    glutMainLoop();

    // Aunque en realidad nunca se llega aqu�, por norma devolvemos 0
    return 0;
}

// Esta funci�n se llama autom�ticamente cada vez que hay que dibujar la ventana
void onDraw() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpiamos la pantalla (borramos lo anterior)
    glDisable(GL_LIGHTING);
    Juego.dibuja();         // Dibujamos el tablero
    glutSwapBuffers();            // Mostramos lo que dibujamos en pantalla

}

void onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Juego.clickRaton(x, y);
        glutPostRedisplay();
    }
}