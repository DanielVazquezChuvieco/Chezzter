#include "freeglut.h"
#include "tablero.h"
#include "juego.h"

juego Juego;

void onDraw(); //esta funcion sera llamada para dibujar

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

    //Equivalente en 2D a gluPerspective LAB
    glMatrixMode(GL_PROJECTION); // Cambiamos al modo de proyección (para ajustar la cámara)
    glLoadIdentity();            // Cargamos una matriz de identidad (sin transformaciones)
    // Usamos una proyección 2D simple, con origen en la esquina superior izquierda
    gluOrtho2D(0, 800, 800, 0);
    glViewport(0, 0, 800, 800); //ajusto lo que se ve entre (0,0) abajo izq y (800,800) arriba dcha.


    // Le decimos a GLUT qué función usar para dibujar
    glutDisplayFunc(onDraw);

    // Entramos en el bucle principal de GLUT (no vuelve nunca)
    glutMainLoop();

    // Aunque en realidad nunca se llega aquí, por norma devolvemos 0
    return 0;
}

// Esta función se llama automáticamente cada vez que hay que dibujar la ventana
void onDraw() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpiamos la pantalla (borramos lo anterior)
    Juego.dibuja();          // Dibujamos el tablero
    glutSwapBuffers();            // Mostramos lo que dibujamos en pantalla
}

