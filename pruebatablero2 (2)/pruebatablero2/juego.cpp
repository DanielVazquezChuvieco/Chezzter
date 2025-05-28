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
#include "tablero.h"

using namespace std;


void juego::dibuja()
{

    if (pantallaFinal.getResultado() != EN_CURSO) {
        std::cout << "FINAL: dibujando pantalla final\n";

        pantallaFinal.dibujar();
        return;
    }
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

        // ✔ Comprobación de límites
        if (filaDestino < 0 || filaDestino >= 8 || colDestino < 0 || colDestino >= 8) {
            cout << "Destino fuera de límites. Movimiento cancelado." << endl;
            piezaArrastrada->setPosicionGrafica();
            piezaArrastrada = nullptr;
            arrastrando = false;
            glutPostRedisplay();
            return;
        }

        // ✔ Movimiento nulo (soltar en la misma casilla)
        if (filaDestino == filaOrigen && colDestino == colOrigen) {
            cout << "Movimiento nulo." << endl;
            piezaArrastrada->setPosicionGrafica();
            piezaArrastrada = nullptr;
            arrastrando = false;
            glutPostRedisplay();
            return;
        }

        // ✔ Comprobar si el movimiento es válido para la pieza
        bool movimientoValido = piezaArrastrada->movimientoValido(
            filaOrigen, colOrigen, filaDestino, colDestino, Tablero
        );

        cout << "Movimiento (" << piezaArrastrada->nombre() << "): " << (movimientoValido ? "VALIDO" : "INVALIDO") << endl;

        if (movimientoValido) {
            // Guardar la pieza en destino (por si hay que deshacer)
            Pieza* compjaque = Tablero.at(filaDestino, colDestino).getPieza();

            // ✔ Verificar que no deja en jaque tras aplicar gravedad
            if (!simularMovimientoConGravedadYVerificar(filaOrigen, colOrigen, filaDestino, colDestino)) {
                cout << "Tu rey quedaría en jaque tras aplicar la gravedad. Movimiento cancelado." << endl;

                // Revertir movimiento
                Tablero.at(filaOrigen, colOrigen).set(piezaArrastrada);
                Tablero.at(filaDestino, colDestino).set(compjaque);
                piezaArrastrada->setFila(filaOrigen);
                piezaArrastrada->setColumna(colOrigen);
                piezaArrastrada->setPosicionGrafica();
            }
            else {
                // ✔ Movimiento aceptado y realizado
                Tablero.at(filaDestino, colDestino).set(piezaArrastrada);
                Tablero.at(filaOrigen, colOrigen).set(nullptr);
                piezaArrastrada->setFila(filaDestino);
                piezaArrastrada->setColumna(colDestino);
                piezaArrastrada->setPosicionGrafica();
                cout << "Movimiento realizado." << endl;

                // Sonido según turno
                if (turnoBlanco)
                    ETSIDI::play("sonidos/astro_move.mp3");
                else
                    ETSIDI::play("sonidos/alien_move2.mp3");

              

                
                if (Tablero.estaEnJaque(!turnoBlanco)) {
                    cout << "¡" << (turnoBlanco ? "BLANCO" : "NEGRO") << " está en JAQUE!" << endl;
                    if (Tablero.esJaqueMate(!turnoBlanco)) {
                        cout << "¡JAQUE MATE! Ha ganado " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
                        pantallaFinal.setResultado(turnoBlanco ? GANA_BLANCAS : GANA_NEGRAS);
                        glutPostRedisplay();
                        return;
                    }
                }
                

                // ✔ Cambio de turno
                turnoBlanco = !turnoBlanco;
                cout << "Nuevo turno: " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
            }
        }
        else {
            cout << "Movimiento inválido. Revisa límites o reglas de la pieza." << endl;
            piezaArrastrada->setPosicionGrafica();
        }
    }
    else {
        cout << "No había pieza seleccionada al soltar." << endl;
    }

    piezaArrastrada = nullptr;
    arrastrando = false;
    glutPostRedisplay();
}


bool juego::simularMovimientoConGravedadYVerificar(int filaOrigen, int colOrigen, int filaDestino, int colDestino) {

       
        tablero copia = Tablero.copiar();

        if (filaOrigen < 0 || filaOrigen >= 8 || colOrigen < 0 || colOrigen >= 8 ||
            filaDestino < 0 || filaDestino >= 8 || colDestino < 0 || colDestino >= 8) {
            std::cerr << "[ERROR] Coordenadas fuera de rango: origen (" << filaOrigen << ", " << colOrigen
                << ") destino (" << filaDestino << ", " << colDestino << ")" << std::endl;
            return false;
        }

    
        Pieza* pieza = copia.at(filaOrigen, colOrigen).getPieza();
        if (!pieza) {
            std::cerr << "[ERROR] No hay pieza en (" << filaOrigen << ", " << colOrigen << ") en la copia" << std::endl;
            return false;
        }

       
        if (!pieza->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, copia)) {
            return false;
        }


        copia.at(filaDestino, colDestino).set(pieza);
        copia.at(filaOrigen, colOrigen).set(nullptr);
        pieza->setFila(filaDestino);
        pieza->setColumna(colDestino);

     
        copia.aplicarGravedad();

        int filaRey, colRey;
        Pieza* rey = copia.encontrarRey(pieza->esBlanca(), filaRey, colRey);
        if (!rey) {
            std::cerr << "[ERROR] El rey ha desaparecido tras la gravedad" << std::endl;
            return false;
        }

        return !copia.estaEnJaque(pieza->esBlanca());

  
}
