#include "freeglut.h"
#include "tablero.h"
#include "juego.h"

<<<<<<< Updated upstream
<<<<<<< Updated upstream
juego Juego;


void onDraw(); //esta funcion sera llamada para dibujar
void onMouseClick(int button, int state, int x, int y);
=======
=======
>>>>>>> Stashed changes
tablero Tablero;
juego Juego;

void onDraw(); //esta funcion sera llamada para dibujar
void onMouseClick(int button, int state, int x, int y);
void OnTimer(int value);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
// Función principal del programa
int main(int argc, char** argv) {
    // Inicializamos GLUT (sistema de ventanas)
    glutInit(&argc, argv);
<<<<<<< Updated upstream
<<<<<<< Updated upstream

    // Usamos doble buffer y modo RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Establecemos el tamaño inicial de la ventana
    glutInitWindowSize(500, 500);

    // Creamos la ventana con el título deseado
    glutCreateWindow("CHEZZTER");

    //Equivalente en 2D a gluPerspective LAB
    glMatrixMode(GL_PROJECTION); // Cambiamos al modo de proyección (para ajustar la cámara)
    glLoadIdentity();            // Cargamos una matriz de identidad (sin transformaciones)
    // Usamos una proyección 2D simple, con origen en la esquina superior izquierda
    gluOrtho2D(0, 800, 800, 0);
    glViewport(0, 0, 800, 800); //ajusto lo que se ve entre (0,0) abajo izq y (800,800) arriba dcha.

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // Le decimos a GLUT qué función usar para dibujar
    glutDisplayFunc(onDraw);

    glutMouseFunc(onMouseClick);


=======
=======
>>>>>>> Stashed changes
   // Usamos doble buffer y modo RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Establecemos el tamaño inicial de la ventana
    glutInitWindowSize(800, 800);
    // Creamos la ventana con el título deseado
    glutCreateWindow("CHEZZTER");

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    //gluPerspective(40.0, 800 / 800.0f, 0.1, 150);
    //Equivalente en 2D a gluPerspective LAB
  // Cambiamos al modo de proyección (para ajustar la cámara)
    glLoadIdentity();            // Cargamos una matriz de identidad (sin transformaciones)
     //funciones de dibujo
    gluOrtho2D(0, 800, 800, 0);
    glViewport(0, 0, 800, 800); //ajusto lo que se ve entre (0,0) abajo izq y (800,800) arriba dcha.
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
                                 // Usamos una proyección 2D simple, con origen en la esquina superior izquierda
   
    // Le decimos a GLUT qué función usar para dibujar

    glutDisplayFunc(onDraw);
    glutTimerFunc(25, OnTimer, 0);

   // glutMouseFunc(onMouseClick);

   // ETSIDI::play("");
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
    // Entramos en el bucle principal de GLUT (no vuelve nunca)
   glutMainLoop();

    // Aunque en realidad nunca se llega aquí, por norma devolvemos 0
    return 0;
}

// Esta función se llama automáticamente cada vez que hay que dibujar la ventana
void onDraw() {
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    glClear(GL_COLOR_BUFFER_BIT); // Limpiamos la pantalla (borramos lo anterior)
    Juego.dibuja();         // Dibujamos el tablero
    glutSwapBuffers();            // Mostramos lo que dibujamos en pantalla
=======
=======
>>>>>>> Stashed changes
    //Borrado de la pantalla	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Para definir el punto de vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
  
    Tablero.dibuja();
   
   
    //no borrar esta linea ni poner nada despues
    glutSwapBuffers();

    
          
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

}

void onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Juego.clickRaton(x, y);
        glutPostRedisplay();
    }
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
}
void OnTimer(int value)
{
    //poner aqui el código de animacion


        //no borrar estas lineas

    glutTimerFunc(25, OnTimer, 0); //25
    glutPostRedisplay();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
}