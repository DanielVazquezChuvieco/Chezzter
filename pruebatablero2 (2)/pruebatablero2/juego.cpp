#include "juego.h"
#include "freeglut.h"
#include "peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include <iostream>
#include "ETSIDI.h"

using namespace std;


void juego::dibuja()
{
    Tablero.dibuja();  //Dibuja el tablero y piezasen pantalla
}


void juego::iniciarArrastre(int x, int y) {
    cout << "\n=== INICIANDO ARRASTRE ===" << endl;
    cout << "Coordenadas click: (" << x << ", " << y << ")" << endl;

    //Convierte las coordenadas de pantalla a la posición de la casilla del tablero y lo muestra por consola
    int fila = (y - 100) / 75;
    int col = (x - 100) / 75;
    cout << "Casilla calculada: (" << fila << ", " << col << ")" << endl;

    if (fila >= 0 && fila < 8 && col >= 0 && col < 8) {  //Comprueba que el clic está dentro del tablero
        if (Tablero.at(fila, col).hayPieza()) {   //Si hay una pieza en la casilla, obtiene un puntero a la pieza y muestra su tipo y color
            Pieza* pieza = Tablero.at(fila, col).getPieza(); // Se coje la posición de la pieza pulsada
            bool esBlanca = pieza->esBlanca(); // Se obtien el color
            std::string colorPieza = esBlanca ? "BLANCO" : "NEGRO";
            cout << "Pieza encontrada: " << pieza->nombre() << " Color: " << colorPieza << endl; //para pillar el tipo de pieza que es, se podría hacer con polimorfismo, pero esto es más comodo

            if (esBlanca != turnoBlanco) { //Default Turnoblanco = 1
                cout << "Intento de mover pieza contraria! Turno actual: " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
                return;
            }
            //Si es el turno correcto, guarda la pieza
            piezaArrastrada = pieza;
            filaOrigen = fila;  //Guarda su posición de origen
            colOrigen = col;
            arrastrando = true;  //activa el modo arrastre

            cout << "Iniciando arrastre de pieza desde (" << filaOrigen << ", " << colOrigen << ")" << endl;
            piezaArrastrada->setPosicionGraficaPixel(x, y);  //actualiza la posición gráfica de la pieza del drag
        }
        else {
            cout << "No hay pieza en (" << fila << ", " << col << ")" << endl;  //Si no hay pieza lo indica
        }
    }
    else {
        cout << "Click fuera del tablero" << endl;  //Si está fuera del tablero lo indica
    }
}

//Mientras el usuario arrastra la pieza, imprime la posición actual del ratón y actualiza la plsicion gráfica de la pieza para que siga el cursos
void juego::actualizarArrastre(int x, int y) {
    if (arrastrando && piezaArrastrada) {
        cout << "Actualizando posicion arrastre: (" << x << ", " << y << ")" << endl;
        piezaArrastrada->setPosicionGraficaPixel(x, y);
        glutPostRedisplay();  //LLamada al glutPostRedisplay para redibujar la pantalla
    }
}

void juego::finalizarArrastre(int x, int y) {
    cout << "\n=== FINALIZANDO ARRASTRE ===" << endl;

    if (arrastrando && piezaArrastrada) {
        int filaDestino = (y - 100) / 75;
        int colDestino = (x - 100) / 75;

        cout << "Destino: (" << filaDestino << ", " << colDestino << ")" << endl;
        cout << "Pieza: " << piezaArrastrada->nombre() << endl;

        if (filaDestino == filaOrigen && colDestino == colOrigen) {
            cout << "Movimiento nulo." << endl;
            piezaArrastrada->setPosicionGrafica();
            piezaArrastrada = nullptr;
            arrastrando = false;
            glutPostRedisplay();
            return;
        }

        bool movimientoValido = false;
        string tipoPieza = piezaArrastrada->nombre();

        // Lógica de validación
        movimientoValido = piezaArrastrada->movimientoValido(
            filaOrigen, colOrigen, filaDestino, colDestino, Tablero
        );

        cout << "Movimiento (" << tipoPieza << "): " << (movimientoValido ? "VALIDO" : "INVALIDO") << endl;

        if (movimientoValido && filaDestino >= 0 && filaDestino < 8 && colDestino >= 0 && colDestino < 8) {
            Pieza* compjaque = Tablero.at(filaDestino, colDestino).getPieza();

            // Simular movimiento
            Tablero.at(filaDestino, colDestino).set(piezaArrastrada);
            Tablero.at(filaOrigen, colOrigen).set(nullptr);
            piezaArrastrada->setFila(filaDestino);
            piezaArrastrada->setColumna(colDestino);

            // Verificar si queda en jaque tras mover
            if (Tablero.estaEnJaque(turnoBlanco)) {
                cout << "Tu rey quedaría en jaque. Movimiento cancelado." << endl;

                // Revertir movimiento
                Tablero.at(filaOrigen, colOrigen).set(piezaArrastrada);
                Tablero.at(filaDestino, colDestino).set(compjaque);
                piezaArrastrada->setFila(filaOrigen);
                piezaArrastrada->setColumna(colOrigen);
                piezaArrastrada->setPosicionGrafica();
            }
            else {
                // Movimiento aceptado
                piezaArrastrada->setPosicionGrafica();
                cout << "Movimiento realizado." << endl;

                // Verificar JAQUE o JAQUE MATE al jugador rival
                bool rivalBlanco = !turnoBlanco;
                if (Tablero.estaEnJaque(rivalBlanco)) {
                    cout << "¡" << (rivalBlanco ? "BLANCO" : "NEGRO") << " está en JAQUE!" << endl;
                    if (Tablero.esJaqueMate(rivalBlanco)) {
                        cout << "¡JAQUE MATE! Ha ganado " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
                    }
                }

                // Cambiar el turno solo si el movimiento fue válido y aceptado
                turnoBlanco = !turnoBlanco;
                cout << "Nuevo turno: " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
            }
        }
        else {
            cout << "Movimiento inválido. Revisa límites o reglas de la pieza." << endl;
            piezaArrastrada->setPosicionGrafica();
        }

        piezaArrastrada = nullptr;
        arrastrando = false;
        Tablero.aplicarGravedad();  //Aplica gravedad si hay huecos debajo
        glutPostRedisplay();
    }
    else {
        cout << "No había pieza seleccionada al soltar." << endl;
    }
}
