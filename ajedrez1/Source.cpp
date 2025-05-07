#include "freeglut.h"
#include <vector>

// Clase base Pieza
class Pieza {
protected:
    float x, y;  // Posición en el tablero

public:
    Pieza(float x_, float y_) : x(x_), y(y_) {}
    virtual void dibuja() = 0;
    virtual ~Pieza() {}
};

// Clase Peon
class Peon : public Pieza {
public:
    Peon(float x_, float y_) : Pieza(x_, y_) {}

    void dibuja() override {
        glPushMatrix();
        glTranslatef(x, y, 0);
        glColor3f(1.0f, 1.0f, 1.0f);  // Color blanco
        glutSolidSphere(0.05, 20, 20);
        glPopMatrix();
    }
};

class Caballo : public Pieza {
public:
    Caballo(float x_, float y_) : Pieza(x_, y_) {}

    void dibuja() override {
        glPushMatrix();
        glTranslatef(x, y, 0);
        glColor3f(1, 1, 1);  // Color blanco
        glutSolidTeapot(0.05);
        glPopMatrix();
    }
};

// Lista de piezas
std::vector<Pieza*> piezas;

// Función para dibujar el tablero
void dibujaTablero() {
    bool blanco = true;
    float size = 0.2f; // Tamaño de cada casilla

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (blanco)
                glColor3f(0, 1.0f, 0); // Blanco
            else
                glColor3f(1, 0.0f, 0.0f); // Negro

            glBegin(GL_QUADS);
            glVertex2f(-1.0f + j * size, -1.0f + i * size);
            glVertex2f(-1.0f + (j + 1) * size, -1.0f + i * size);
            glVertex2f(-1.0f + (j + 1) * size, -1.0f + (i + 1) * size);
            glVertex2f(-1.0f + j * size, -1.0f + (i + 1) * size);
            glEnd();

            blanco = !blanco;
        }
        blanco = !blanco;
    }
}

// Función de dibujo
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    dibujaTablero(); // Dibujar el tablero

    // Dibujar todas las piezas
    for (auto pieza : piezas) {
        pieza->dibuja();
    }

    glFlush();
}

// Programa principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Ajedrez 2D FreeGLUT");

    // Inicializar las piezas
    piezas.push_back(new Peon(-0.9f, -0.7f));
    piezas.push_back(new Peon(-0.7f, -0.7f));
    piezas.push_back(new Peon(-0.5f, -0.7f));
    piezas.push_back(new Peon(-0.3f, -0.7f));
    piezas.push_back(new Peon(-0.1f, -0.7f));
    piezas.push_back(new Peon(0.1f, -0.7f));
    piezas.push_back(new Peon(0.3f, -0.7f));
    piezas.push_back(new Peon(0.5f, -0.7f));


    piezas.push_back(new Caballo(-0.7f, -0.9f));
    piezas.push_back(new Caballo(0.3f, -0.9f));

   


    glutDisplayFunc(display);
    glutMainLoop();

    // Liberar memoria (aunque no se llega aquí en GLUT normalmente)
    for (auto pieza : piezas) {
        delete pieza;
    }

    return 0;
}

