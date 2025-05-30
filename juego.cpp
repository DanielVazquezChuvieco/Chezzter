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
            << (movimientoValido ? "VÁLIDO" : "INVÁLIDO") << std::endl;

        if (movimientoValido && filaDestino >= 0 && filaDestino < 8 && colDestino >= 0 && colDestino < 8 ) {
            Pieza* destinoAnterior = Tablero.at(filaDestino, colDestino).getPieza();

            // Simular para evitar mover a jaque
            if (!simularMovimientoConGravedadYVerificar(filaOrigen, colOrigen, filaDestino, colDestino)) {
                std::cout << "Movimiento dejaría al rey en jaque. Cancelado." << std::endl;
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
              
                }    

                cout << "Movimiento realizado." << endl;

                // Sonido segÃºn turno
                if (turnoBlanco) {
                    ETSIDI::play("sonidos/astro_move.mp3"); // Sonido para piezas blancas
                }
                else {
                    ETSIDI::play("sonidos/alien_move2.mp3");  // Sonido para piezas negras
                }
                turnoBlanco = !turnoBlanco;
                std::cout << "Nuevo turno: " << (turnoBlanco ? "BLANCO" : "NEGRO") << std::endl;
        }
        else {
            std::cout << "Movimiento inválido." << std::endl;
            piezaArrastrada->setPosicionGrafica();
        }
    }
    else {
        std::cout << "No había pieza seleccionada." << std::endl;
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

void juego::postGravedad() {
    // Verificar jaque y jaque mate al rival
    bool rivalBlanco = turnoBlanco;
    if (Tablero.estaEnJaque(rivalBlanco)) {
        std::cout << "¡" << (rivalBlanco ? "BLANCO" : "NEGRO") << " está en JAQUE!" << std::endl;
        if (Tablero.esJaqueMate(rivalBlanco)) {
            std::cout << "¡JAQUE MATE! Ha ganado " << (turnoBlanco ? "NEGRO" : "BLANCO") << std::endl;
        }
    }

    // Cambiar turno tras todo el proceso
   //turnoBlanco = !turnoBlanco;
 //  std::cout << "Nuevo turno: " << (turnoBlanco ? "BLANCO" : "NEGRO") << std::endl;
}
