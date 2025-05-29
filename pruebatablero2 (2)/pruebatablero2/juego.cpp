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


void juego::dibuja() {
    Tablero.dibuja();
    if (!arrastrando) {
        Tablero.animarCaidaGravedad();  // Solo animaci�n visual
    }
}




void juego::iniciarArrastre(int x, int y) {
    cout << "\n=== INICIANDO ARRASTRE ===" << endl;
    cout << "Coordenadas click: (" << x << ", " << y << ")" << endl;

    //Convierte las coordenadas de pantalla a la posici�n de la casilla del tablero y lo muestra por consola
    int fila = (y - 100) / 75;
    int col = (x - 100) / 75;
    cout << "Casilla calculada: (" << fila << ", " << col << ")" << endl;

    if (fila >= 0 && fila < 8 && col >= 0 && col < 8) {  //Comprueba que el clic est� dentro del tablero
        if (Tablero.at(fila, col).hayPieza()) {   //Si hay una pieza en la casilla, obtiene un puntero a la pieza y muestra su tipo y color
            Pieza* pieza = Tablero.at(fila, col).getPieza(); // Se coje la posici�n de la pieza pulsada
            bool esBlanca = pieza->esBlanca(); // Se obtien el color
            //std::string colorPieza = esBlanca ? "BLANCO" : "NEGRO";
            cout << "Pieza encontrada: " << pieza->nombre() << " de los: " << (esBlanca ? "Astronautas" : "Aliens") << endl; //para pillar el tipo de pieza que es, se podr�a hacer con polimorfismo, pero esto es m�s comodo

            if (esBlanca != turnoBlanco) { //Default Turnoblanco = 1
                cout << "Intento de mover pieza contraria! Turno actual: " << (turnoBlanco ? "Astronautas" : "Aliens") << endl;
                return;
            }
            //Si es el turno correcto, guarda la pieza
            piezaArrastrada = pieza;
            filaOrigen = fila;  //Guarda su posici�n de origen
            colOrigen = col;
            arrastrando = true;  //activa el modo arrastre

            cout << "Iniciando arrastre de pieza desde (" << filaOrigen << ", " << colOrigen << ")" << endl;
            piezaArrastrada->setPosicionGraficaPixel(x, y);  //actualiza la posici�n gr�fica de la pieza del drag
        }
        else {
            cout << "No hay vida en (" << fila << ", " << col << ")" << endl;  //Si no hay pieza lo indica
        }
    }
    else {
        cout << "Click fuera de la galxia" << endl;  //Si est� fuera del tablero lo indica
    }
}

//Mientras el usuario arrastra la pieza, imprime la posici�n actual del rat�n y actualiza la plsicion gr�fica de la pieza para que siga el cursos
void juego::actualizarArrastre(int x, int y) {
    if (arrastrando && piezaArrastrada) {
        cout << "Actualizando posicion arrastre: (" << x << ", " << y << ")" << endl;
        piezaArrastrada->setPosicionGraficaPixel(x, y);
        glutPostRedisplay();  //LLamada al glutPostRedisplay para redibujar la pantalla
    }
}

void juego::finalizarArrastre(int x, int y) {
    std::cout << "\n=== FINALIZANDO ARRASTRE ===" << std::endl;

    if (arrastrando && piezaArrastrada) {
        int filaDestino = (y - 100) / 75;
        int colDestino = (x - 100) / 75;

        if (filaDestino == filaOrigen && colDestino == colOrigen) {
            std::cout << "Movimiento nulo." << std::endl;
            piezaArrastrada->setPosicionGrafica();
            piezaArrastrada = nullptr;
            arrastrando = false;
            glutPostRedisplay();
            return;
        }

        bool movimientoValido = piezaArrastrada->movimientoValido(
            filaOrigen, colOrigen, filaDestino, colDestino, Tablero
        );

        std::cout << "Intentando mover " << piezaArrastrada->nombre()
            << " de (" << filaOrigen << ", " << colOrigen << ") a ("
            << filaDestino << ", " << colDestino << "): "
            << (movimientoValido ? "Valido" : "Invalido") << std::endl;

        if (movimientoValido && filaDestino >= 0 && filaDestino < 8 && colDestino >= 0 && colDestino < 8) {
            Pieza* destinoAnterior = Tablero.at(filaDestino, colDestino).getPieza();

            // Simular para evitar mover a jaque
            if (!simularMovimientoConGravedadYVerificar(filaOrigen, colOrigen, filaDestino, colDestino)) {
                std::cout << "Movimiento dejaria al rey en jaque. No se puede." << std::endl;
                piezaArrastrada->setPosicionGrafica();
            }
            else {
                // Ejecutar el movimiento real
                Tablero.at(filaDestino, colDestino).set(piezaArrastrada);
                Tablero.at(filaOrigen, colOrigen).set(nullptr);
                piezaArrastrada->setFila(filaDestino);
                piezaArrastrada->setColumna(colDestino);
                piezaArrastrada->setPosicionGrafica();

                std::cout << "Movimiento realizado correctamente." << std::endl;

                // Aplicar gravedad real
                Tablero.aplicarGravedad();

                // Verificar jaque y jaque mate al rival
                bool rivalBlanco = !turnoBlanco;
                if (Tablero.estaEnJaque(rivalBlanco)) {
                    std::cout<<"CUIDADO " << (rivalBlanco ? "ASTRONAUTAS" : "ALIENS") << " esta en JAQUE!" << std::endl;
                    if (Tablero.esJaqueMate(rivalBlanco)) {
                        std::cout << "JAQUE MATE! Han ganado " << (turnoBlanco ? "ASTRONAUTAS" : "ALIENS") << std::endl;
                    }
                }

                // Cambiar turno tras todo el proceso
                turnoBlanco = !turnoBlanco;
                std::cout << "Nuevo turno: " << (turnoBlanco ? "Astronautas" : "Aliens") << std::endl;
            }
        }
        else {
            std::cout << "Movimiento invalido." << std::endl;
            piezaArrastrada->setPosicionGrafica();
        }
    }
    else {
        std::cout << "No hay vida seleccionada en ese hueco." << std::endl;
    }

    piezaArrastrada = nullptr;
    arrastrando = false;
    glutPostRedisplay();
}


bool juego::simularMovimientoConGravedadYVerificar(int filaOrigen, int colOrigen, int filaDestino, int colDestino) {
    tablero copia = Tablero.copiar();
    
    Pieza* pieza = copia.at(filaOrigen, colOrigen).getPieza();

    if (!pieza->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, copia))
        return false;

    // Movimiento simulado
    copia.at(filaDestino, colDestino).set(pieza);
    copia.at(filaOrigen, colOrigen).set(nullptr);
    pieza->setFila(filaDestino);
    pieza->setColumna(colDestino);

    // Aplicar gravedad
    copia.aplicarGravedad();

    // Verificar si el rey queda en jaque
    return !copia.estaEnJaque(pieza->esBlanca());
}
